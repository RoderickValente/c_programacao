#include <stdio.h>
#include <string.h>

#define NOMES 4
#define CARAC 32

int main()
{
    char nomes[NOMES][CARAC], nome_maior[CARAC];
    int idx, maior;

    for (idx = 0; idx < NOMES; idx++)
    {
        printf("Digite o nome %d: ", idx+1);
        gets(nomes[idx]);
    }

    for (idx = 0; idx < NOMES; idx++)
    {
        printf("Nome %d: %s\n", idx+1, nomes[idx]);
    }

    maior = 0;

    for (idx = 0; idx < NOMES; idx++)
    {
        int len = strlen(nomes[idx]);

        if (len > maior)
        {
            maior = len;
            strcpy(nome_maior, nomes[idx]);
        }
    }

    printf("O maior nome digitado foi %s com %d caracteres.\n",
        nome_maior, maior);

    maior = 0;

    for (idx = 1; idx < NOMES; idx++)
    {
        if (strcmp(nomes[maior], nomes[idx]) < 0)
        {
            maior = idx;
        }
    }

    printf("Na ordem alfabética, o maior nome digitado foi %s.\n",
        nomes[maior]);

    return 0;
}