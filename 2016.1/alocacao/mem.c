#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
    unsigned int arr1[5] = {10,20,30,40,50};
    unsigned int arr2[5];

    memset((void*) arr2, 0, 5*sizeof(int));
    memcpy((void*) (arr2+2), (void*) (arr1+2), 3*sizeof(int));

    printf("arr1 = {%u,%u,%u,%u,%u}\n", arr1[0],arr1[1],arr1[2],arr1[3],arr1[4]);
    printf("arr2 = {%u,%u,%u,%u,%u}\n", arr2[0],arr2[1],arr2[2],arr2[3],arr2[4]);

    return 0;
}