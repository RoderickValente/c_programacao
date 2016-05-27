#include <stdio.h>

int main()
{
    int arr1[5] = {10,20,30,40,50};
    char *p;

    p = arr1+2;

    printf("arr1=%lu\n", arr1);
    printf("arr1+1=%lu\n", arr1+1);

    p[1] = 99;

    printf("arr1[2]=%lu\n", arr1[2]);
    printf("arr1+2=%lu\n", *(arr1+2));

    return 0;
}
