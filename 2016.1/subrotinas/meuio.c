#include "meuio.h"

char input_char(const char* prompt)
{
    printf("%s", prompt);
    return getch();
}

void flush()
{
    char opcao;

    do
    {
        opcao = getchar();
    }
    while (opcao != '\n');
}

char getch()
{
    char ch;

    scanf(" %c", &ch);
    flush();

    return ch;
}