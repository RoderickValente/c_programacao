#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr;

    arr = (int*) calloc(20, sizeof(int));
    free(arr);

    return 0;
}