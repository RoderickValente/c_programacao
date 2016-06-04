#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "arquivo.h"

typedef struct
{
    char* nome;
    char* cnh;
    float vl_diaria;
    unsigned int limite_km;
    unsigned int km_retirada;
    float vl_km_extra;
    char* data_retirada;
    boolean devolvido;
} T_Retirada;

unsigned int opcao_menu();
void limpa_retirada(T_Retirada* retirada);
boolean fazer_retirada(T_Retirada* retirada);
void fazer_devolucao(T_Retirada* retiradas, unsigned int qtd_retiradas);
void escreve_retiradas(FILE* arq, T_Retirada* retiradas, unsigned int qtd_retiradas);
unsigned int le_retiradas(FILE* arq, T_Retirada** retiradas);
void escreve_retirada(FILE* arq, T_Retirada* retirada);
void le_retirada(FILE* arq, T_Retirada* retirada);

int main(int argc, char* argv[])
{
    T_Retirada* retiradas = NULL;
    unsigned int qtd_retiradas = 0;
    unsigned int opcao = 0;
    unsigned char running = 1;
    FILE* arquivo = NULL;

    arquivo = fopen("locadora.dat", "rb");
    if (arquivo)
    {
        qtd_retiradas = le_retiradas(arquivo, &retiradas);
        fclose(arquivo);
    }

    while (running)
    {
        opcao = opcao_menu();

        switch (opcao)
        {
            case 1: 
            {
                retiradas = (T_Retirada*) realloc((void*) retiradas, ++qtd_retiradas * sizeof(T_Retirada));

                if (!fazer_retirada(&(retiradas[qtd_retiradas-1])))
                {
                    retiradas = (T_Retirada*) realloc((void*) retiradas, --qtd_retiradas * sizeof(T_Retirada));
                }

                break;
            }
            case 2: fazer_devolucao(retiradas, qtd_retiradas); break;
            case 3: running = 0; break;
        }
    }

    if (retiradas)
    {
        unsigned int idx = 0;
        FILE* arquivo = NULL;

        arquivo = fopen("locadora.dat", "wb");

        if (arquivo)
        {
            escreve_retiradas(arquivo, retiradas, qtd_retiradas);
            fclose(arquivo);
        }

        for (; idx < qtd_retiradas; idx++)
            limpa_retirada(&(retiradas[idx]));

        free(retiradas);
    }

    return 0;
}

unsigned int opcao_menu()
{
    unsigned int opcao = 0;

    printf("\n");
    printf("--------------------\n");
    printf("LOCADORA DE VEÍCULOS\n");
    printf("--------------------\n");
    printf("1 - Retirada        \n");
    printf("2 - Devolução       \n");
    printf("3 - Sair            \n");
    printf("--                  \n");

    do
    {
        ler_inteiro("Opção: ", &opcao);
    } while ((opcao < 1) || (opcao > 3));

    return opcao;
}

void limpa_retirada(T_Retirada* retirada)
{
    if (retirada->nome) free(retirada->nome);
    if (retirada->cnh) free(retirada->cnh);
    if (retirada->data_retirada) free(retirada->data_retirada);
}

boolean fazer_retirada(T_Retirada* retirada)
{
    char confirmacao;
    boolean retirada_ok = true;

    memset((void*) retirada, 0, sizeof(T_Retirada));

    retirada->devolvido = false;

    printf("\n");
    printf("-------------------\n");
    printf("RETIRADA DE VEÍCULO\n");
    printf("-------------------\n");

    ler_string_dinamica("Nome: ", &(retirada->nome));
    ler_string_dinamica("CNH: ", &(retirada->cnh));
    ler_real("Valor da diária: R$", &(retirada->vl_diaria));
    ler_inteiro("Limite KM: ", &(retirada->limite_km));
    ler_inteiro("KM retirada: ", &(retirada->km_retirada));
    ler_real("Valor KM extra: R$", &(retirada->vl_km_extra));
    ler_string_dinamica("Data de retirada: ", &(retirada->data_retirada));

    ler_caractere("Confirma a retirada (S/N)? ", &confirmacao);
    if (confirmacao != 'S')
    {
        retirada_ok = false;
        limpa_retirada(retirada);
    }

    return retirada_ok;
}

void fazer_devolucao(T_Retirada* retiradas, unsigned int qtd_retiradas)
{
    unsigned int idx;
    unsigned int opcao = 0;

    printf("\n");
    printf("--------------------\n");
    printf("DEVOLUÇÃO DE VEÍCULO\n");
    printf("--------------------\n");

    for (idx = 0; idx < qtd_retiradas; idx++)
    {
        printf("%d - %s", idx+1, retiradas[idx].nome);
        if (retiradas[idx].devolvido)
            printf(" (devolvido)");
        printf("\n");
    }

    printf("--\n");

    do
    {
        ler_inteiro("Opção (0 para voltar): ", &opcao);
    } while (opcao > qtd_retiradas);

    if (opcao != 0)
    {
        T_Retirada* retirada = &(retiradas[opcao-1]);

        printf("\n");

        if (retirada->devolvido)
        {
            printf("Esta retirada já foi devolvida anteriormente.\n");
        }
        else
        {
            char confirmacao;
            unsigned int qtd_diarias = 0;
            unsigned int km_atual = 0;
            float vl_adicional = 0, total = 0;

            printf("Nome: %s\n", retirada->nome);
            printf("Data: %s\n", retirada->data_retirada);
            printf("-----\n");

            ler_inteiro("Diárias utilizadas: ", &qtd_diarias);
            ler_inteiro("KM atual: ", &km_atual);
            ler_real("Adicional: R$", &vl_adicional);

            total = qtd_diarias * retirada->vl_diaria + vl_adicional;
            if (retirada->limite_km)
            {
                int km_extras = km_atual 
                    - retirada->km_retirada - retirada->limite_km;

                if (km_extras > 0)
                    total = total + (km_extras * retirada->vl_km_extra);
            }

            printf("-----\n");
            printf("Total a pagar: R$%.2f\n\n", total);

            ler_caractere("Confirma a devolução (S/N)? ", &confirmacao);
            if (confirmacao == 'S')
            {
                retirada->devolvido = true;
            }
        }
    }
}

void escreve_retiradas(FILE* arq, T_Retirada* retiradas, unsigned int qtd_retiradas)
{
    unsigned int idx;
    escreve_int(arq, &qtd_retiradas);
    for (idx = 0; idx < qtd_retiradas; idx++)
        escreve_retirada(arq, &(retiradas[idx]));
}

unsigned int le_retiradas(FILE* arq, T_Retirada** retiradas)
{
    unsigned int idx;
    unsigned int qtd_retiradas;

    le_int(arq, &qtd_retiradas);

    *retiradas = malloc(qtd_retiradas * sizeof(T_Retirada));

    for (idx = 0; idx < qtd_retiradas; idx++)
        le_retirada(arq, &((*retiradas)[idx]));

    return qtd_retiradas;
}

void escreve_retirada(FILE* arq, T_Retirada* retirada)
{
    escreve_str(arq, retirada->nome);
    escreve_str(arq, retirada->cnh);
    escreve_float(arq, &(retirada->vl_diaria));
    escreve_int(arq, &(retirada->limite_km));
    escreve_int(arq, &(retirada->km_retirada));
    escreve_float(arq, &(retirada->vl_km_extra));
    escreve_str(arq, retirada->data_retirada);
    escreve_boolean(arq, &(retirada->devolvido));
}

void le_retirada(FILE* arq, T_Retirada* retirada)
{
    memset(retirada, 0, sizeof(T_Retirada));

    le_str(arq, &(retirada->nome));
    le_str(arq, &(retirada->cnh));
    le_float(arq, &(retirada->vl_diaria));
    le_int(arq, &(retirada->limite_km));
    le_int(arq, &(retirada->km_retirada));
    le_float(arq, &(retirada->vl_km_extra));
    le_str(arq, &(retirada->data_retirada));
    le_boolean(arq, &(retirada->devolvido));
}
