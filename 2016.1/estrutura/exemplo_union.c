#include <stdio.h>

#define ST_Test 5

typedef unsigned char byte;

typedef struct
{
    int campoInt;
    char campoChar;
} T_Test;

typedef union
{
    T_Test st;
    byte arr[ST_Test];
} T_UTest;

int main()
{
    T_UTest x;

    x.st.campoInt = 10;
    x.st.campoChar = 'A';

    printf("Campo int: %i\n", x.st.campoInt);
    printf("Campo chr: %c\n", x.st.campoChar);
    x.arr[3] = 66;
    printf("Campo int: %i\n", x.st.campoInt);
    printf("Campo chr: %c\n", x.st.campoChar);

    return 0;
}







