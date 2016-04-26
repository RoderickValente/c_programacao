#include <stdio.h>
#include <string.h>

int main()
{
    char nome[32], sobrenome[64];

    printf("Digite seu nome: ");
    gets(nome);
    printf("Digite seu sobrenome: ");
    gets(sobrenome);

    strcat(sobrenome, ", ");
    strcat(sobrenome, nome);

    printf("Resultado: %s\n", sobrenome);

    return 0;
}