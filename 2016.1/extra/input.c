#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

void flush()
{
    char ch;

    do
    {
        ch = getchar();
    } while (ch != '\n');
}

void ler_caractere(const char* prompt, char* var)
{
    printf("%s", prompt);
    scanf("%c", var);
    flush();
}

void ler_inteiro(const char* prompt, unsigned int* var)
{
    printf("%s", prompt);
    scanf("%u", var);
    flush();
}

void ler_string_dinamica(const char* prompt, char** var)
{
    char str[256];

    printf("%s", prompt);
    fgets(str, 256, stdin);

    *var = realloc((void*) *var, strlen(str));
    memcpy((void*) *var, (void*) str, strlen(str)-1);
    (*var)[strlen(str)-1] = 0;
}

void ler_real(const char* prompt, float* var)
{
    printf("%s", prompt);
    scanf("%f", var);
    flush();
}