#include <stdio.h>

int main()
{
    int x = 10;
    int *p = &x;
    int **q = &p;

    printf("X=%lu\n", x);
    printf("P=%lu\n", p);
    printf("Q=%lu\n", q);
    printf("&X=%lu\n", &x);
    printf("&P=%lu\n", &p);
    printf("&Q=%lu\n", &q);

    **q = *p * x;

    printf("X=%lu\n", x);
    printf("P=%lu\n", p);
    printf("Q=%lu\n", q);

    

    return 0;
}








