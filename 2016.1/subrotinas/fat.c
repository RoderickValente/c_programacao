#include <stdio.h>

unsigned long fat(unsigned long);

int main()
{
    unsigned long numero;

    printf("Fatorial de: ");
    scanf("%lu", &numero);
    printf("Igual a: %lu\n", fat(numero));

    return 0;
}


unsigned long fat(unsigned long num)
{
    if (num <= 1)
        return 1;
    return num*fat(num-1);
}


