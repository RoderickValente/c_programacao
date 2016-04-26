#include <stdio.h>

int main(int argc, char* argv[])
{
    char nomes[10][64];

    puts("Bonitão, qual é o seu nome?");
    gets(nomes[0]);

    printf("Seu nome é %s\n", nomes[0]);

    return 0;
}