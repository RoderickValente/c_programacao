#include <stdio.h>
#define QTD_MEDIAS 20
#define INVALIDO -666

int main(int argc, char* argv[])
{
    int idx, jdx, maiorJdx;
    float maior;
    float medias[QTD_MEDIAS] = {0};

    for (idx = 0; idx < QTD_MEDIAS; idx++)
    {
        printf("Digite a média %i: ", idx+1);
        scanf("%f", &medias[idx]);
    }

    for (idx = 0; idx < QTD_MEDIAS; idx++)
    {
        maior = INVALIDO;

        for (jdx = 0; jdx < QTD_MEDIAS; jdx++)
        {
            if (medias[jdx] > maior)
            {
                maior = medias[jdx];
                maiorJdx = jdx;
            }
        }

        medias[maiorJdx] = INVALIDO;
        printf("Média %i: %.1f\n", idx+1, maior);
    }

    return 0;
}



