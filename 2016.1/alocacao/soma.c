#include <stdio.h>
#include <stdlib.h>

void exibe_inteiros(int* arr, int len)
{
    int idx;

    for (idx = 0; idx < len; idx++)
    {
        printf("%d", arr[idx]);
        if (idx < len-1)
            printf(", ");
    }
}

int main()
{
    int* numeros = NULL;
    int qtd_numeros = 0, numero_digitado = 0, soma = 0;
    
    do
    {
        printf("Digite um número (0 para pegar o beco): ");
        scanf("%d", &numero_digitado);
        soma += numero_digitado;
        qtd_numeros++;

        numeros = (int*) realloc(numeros, qtd_numeros*sizeof(int));
        numeros[qtd_numeros-1] = numero_digitado;
    } while (numero_digitado != 0);

    printf("\nNúmeros: ");
    exibe_inteiros(numeros, qtd_numeros);
    printf("\n\nSoma = %d\n\n", soma);
    free(numeros);

    return 0;
}
