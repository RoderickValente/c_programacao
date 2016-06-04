#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

void escreve_boolean(FILE* arq, boolean* var)
{
    fwrite(var, sizeof(boolean), 1, arq);
}

void le_boolean(FILE* arq, boolean* var)
{
    fread(var, sizeof(boolean), 1, arq);
}

void escreve_int(FILE* arq, unsigned int* var)
{
    fwrite(var, sizeof(unsigned int), 1, arq);
}

void le_int(FILE* arq, unsigned int* var)
{
    fread(var, sizeof(unsigned int), 1, arq);
}

void escreve_float(FILE* arq, float* var)
{
    fwrite(var, sizeof(float), 1, arq);
}

void le_float(FILE* arq, float* var)
{
    fread(var, sizeof(float), 1, arq);
}

void escreve_str(FILE* arq, char* str)
{
    int len = strlen(str);
    fwrite(&len, sizeof(int), 1, arq);
    fwrite(str, sizeof(char), len, arq);
}

void le_str(FILE* arq, char** str)
{
    int len;
    fread(&len, sizeof(int), 1, arq);

    *str = malloc((len+1) * sizeof(char));
    memset(*str, 0, (len+1) * sizeof(char));

    fread(*str, sizeof(char), len, arq);
}