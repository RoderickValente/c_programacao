#include <stdio.h>
#define NUM_NOTAS 5

int main() 
{
    float media = 0;
    int idx;

    for (idx = 0; idx < NUM_NOTAS; idx++)
    {
        float nota;

        printf("Digite a nota %d: ", idx+1);
        scanf("%f", &nota);

        if ((nota >= 0) && (nota <= 10))
        {
            media += nota;
        }
        else
        {
            puts("Nota inválida! Por favor, digite novamente.");
            idx--;
        }
    }

    media /= NUM_NOTAS;
    printf("Média = %.2f\n", media);

    return 0;
}