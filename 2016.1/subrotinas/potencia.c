#include <stdio.h>

int pot(int b, int e)
{
    int total, idx;

    for (total = 1, idx = 1; idx <= e; idx++, total *= b);

    return total;
}

int main()
{
    int base, expoente;

    printf("Digite a base: ");
    scanf("%i", &base);
    printf("Digite o expoente: ");
    scanf("%i", &expoente);

    printf("Total: %i\n", pot(base, expoente));

    printf("5 elevado 6: %i\n", pot(5, 6));

    printf("10 elevado 2: %i\n", pot(10, 2));

    return 0;
}