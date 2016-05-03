#include <stdio.h>

float RAIZQUADRADA(float numero)
{
    int i;
    float raiz = 0;

    for (i = 1; i < numero; i++)
    {
        if ((i * i) >= numero)
        {
            raiz = i;
            break;
        }
    }

    if ((i * i) > numero)
    {
        raiz = i - 1;

        for (; (raiz * raiz) < numero; raiz += 0.001);

        if ((raiz * raiz) > numero)
            raiz -= 0.001;

    }

    return raiz;
}

int main()
{
    float n;

    printf("Digite um número: ");
    scanf("%f", &n);
    printf("Raíz de %f é %f\n\n", n, RAIZQUADRADA(n));

    return 0;
}

