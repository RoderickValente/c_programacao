#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* nome;
    int idade;
} T_Pessoa;

void ler(T_Pessoa *pessoa)
{
    FILE* arq = NULL;

    arq = fopen("binario2.pes", "rb");
    if (arq)
    {
        int len;

        fread(&(pessoa->idade), sizeof(int), 1, arq);
        fread(&len, sizeof(int), 1, arq);

        pessoa->nome = malloc(len * sizeof(char));
        fread(pessoa->nome, sizeof(char), len, arq);

        fclose(arq);
    }
}

void escrever(T_Pessoa* pessoa)
{
    FILE* arq = NULL;

    arq = fopen("binario2.pes", "wb");
    if (arq)
    {
        int len = strlen(pessoa->nome)+1;

        fwrite(&(pessoa->idade), sizeof(int), 1, arq);
        fwrite(&len, sizeof(int), 1, arq);
        fwrite(pessoa->nome, sizeof(char), len, arq);

        fclose(arq);
    }
}

void imprimir()
{
    
}

int main()
{
    T_Pessoa pessoa = {0};

    ler(&pessoa);
    printf("Nome: %s, idade: %d\n", pessoa.nome, pessoa.idade);

    /*char chumbada[] = "Carlos Eduardo";

    pessoa.nome = malloc((strlen(chumbada) + 1) * sizeof(char));
    strcpy(pessoa.nome, chumbada);
    pessoa.idade = 30;
    escrever(&pessoa);*/

    if (pessoa.nome)
        free(pessoa.nome);

    return 0;
}