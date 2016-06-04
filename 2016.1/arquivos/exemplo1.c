#include <stdio.h>
#include <stdio_ext.h>

typedef struct
{
    char nome[64];
    unsigned char idade;
} T_Pessoa;

int main()
{
    FILE* arquivo = NULL;

    arquivo = fopen("exemplo1", "a");

    if (arquivo)
    {
        T_Pessoa pessoa;

        printf("Nome: ");
        gets(pessoa.nome);
        __fpurge(stdin);

        printf("Idade: ");
        scanf("%u", &(pessoa.idade));
        __fpurge(stdin);

        fprintf(arquivo, "%s,%d\n", pessoa.nome, pessoa.idade);

        fclose(arquivo);
    }

    return 0;
}

