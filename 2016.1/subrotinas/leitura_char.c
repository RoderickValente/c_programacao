#include "meuio.h"

int soma_dobro(int* x, int* y)
{
    /*x *= 2;
    y *= 2;*/
    *x = *x * 2;
    *y = *y * 2;

    return *x + *y;
}

int main()
{
    int num1, num2;

    num1 = 10;
    num2 = 20;

    printf("Soma do dobro: %d\n", soma_dobro(&num1, &num2));
    printf("Número 1: %d\n", num1);
    printf("Número 2: %d\n", num2);

    /*char opcao1, opcao2;

    opcao1 = input_char("Digite a primeira opção: ");
    opcao2 = input_char("Digite a segunda opção: ");

    printf("\n\nOpção 1: %c\nOpção 2: %c\n", opcao1, opcao2);*/

    return 0;
}
