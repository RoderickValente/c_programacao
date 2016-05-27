#include <stdio.h>

int main()
{
    int x, y;
    int *p, *q;

    x = 10;
    y = 20;

    p = &x;
    q = &y;

    printf("Endereço de x: %p\n", &x);
    printf("Endereço de y: %p\n", &y);
    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);
    printf("Endereço de p: %p\n", &p);
    printf("Endereço de q: %p\n", &q);
    printf("Valor de p: %p\n", p);
    printf("Valor de q: %p\n", q);

    *p = *p * 2;
    printf("Valor de x: %d\n", x);
    printf("Valor de *p: %d\n", *p);

    return 0;
}








