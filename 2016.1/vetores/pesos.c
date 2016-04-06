#include <stdio.h>

#define MAX 10

int main(int argc, char* argv[])
{
    int idx;
    float vet[MAX] = {0};
    float maior_peso, menor_peso, media_peso;

    for (idx = 0; idx < MAX; idx++)
    {
        printf("Digite o peso da pessoa %i: ", idx+1);
        scanf("%f", &vet[idx]);
    }

    maior_peso = menor_peso = media_peso = vet[0];
    for (idx = 1; idx < MAX; idx++)
    {
        media_peso += vet[idx];

        if (vet[idx] > maior_peso)
            maior_peso = vet[idx];

        if (vet[idx] < menor_peso)
            menor_peso = vet[idx];
    }
    media_peso /= MAX;

    printf("Média peso = %.2f\n", media_peso);
    printf("Maior peso = %.2f\n", maior_peso);
    printf("Menor peso = %.2f\n", menor_peso);

    return 0;
}