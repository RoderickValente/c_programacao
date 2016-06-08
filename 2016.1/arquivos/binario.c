#include <stdio.h>

void ler(int* x, int qtd)
{
    FILE* arq = NULL;

    arq = fopen("binario.xyz", "rb");

    if (arq)
    {
        fread(x, sizeof(int), qtd, arq);
        fclose(arq);
    }
}

void escrever(int* x, int qtd)
{
    FILE* arq = NULL;

    arq = fopen("binario.xyz", "wb");

    if (arq)
    {
        fwrite(x, sizeof(int), qtd, arq);
        fclose(arq);
    }
}

void imprimir(int* x, int qtd)
{
    int idx;
    printf("[");
    for (idx = 0; idx < qtd; idx++)
    {
        printf("%d", x[idx]);
        if (idx < (qtd-1))
            printf(",");
    }
    printf("]\n");
}

void dobrar(int* x, int qtd)
{
    int idx;
    for (idx = 0; idx < qtd; idx++)
    {
        x[idx] *= 2;
    }
}

int main()
{
    int x[5] = {1,2,3,4,5};

    ler(x, 5);
    imprimir(x, 5);
    dobrar(x, 5);
    escrever(x, 5);

    return 0;
}