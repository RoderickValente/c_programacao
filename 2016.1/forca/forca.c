#include <stdio.h>
#include <string.h>
#include "ranking.h"

void print_rpad(char* str, unsigned int columns)
{
    int idx, len = columns - strlen(str);

    for (idx = 0; idx < len; idx++)
        printf(" ");
}

void print_ranking(T_Recorde* ranking)
{
    printf("\nRANKING ATUALIZADO:\n");
    if (ranking)
    {
        T_Recorde* recorde = ranking;
        int posicao = 1;

        while (recorde)
        {
            printf("#%02d %s", posicao++, recorde->nome);
            print_rpad(recorde->nome, 20);
            printf("%8u\n", recorde->pontuacao);

            recorde = recorde->prox;
        }
    }
    printf("\n");
}

int main()
{
    T_Recorde* ranking = NULL;
    unsigned int pontuacao;
    int recorde;

    printf("Pontuação: ");
    scanf("%u", &pontuacao);

    recorde = numero_recorde(pontuacao);
    if (recorde > 0)
    {
        char nome[64];
        printf("Parabéns! Você quebrou o recorde #%d\n", recorde);
        printf("Qual é o seu nome? ");
        scanf("%s", nome);
        inserir_recorde(nome, pontuacao);
    }
    else
    {
        printf("Você não quebrou um recorde :(\n");
    }

    ranking = obter_ranking();
    print_ranking(ranking);
    destruir_ranking(ranking);

    return 0;
}
