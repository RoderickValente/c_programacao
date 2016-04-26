#include <stdio.h>
#include <string.h>

#define COR "preto"
#define TENTATIVAS 4

int main()
{
    int tentativa;
    char cor[32];

    for (tentativa = 1; tentativa <= TENTATIVAS; tentativa++)
    {
        printf("Qual é a cor que eu estou pensando? ");
        gets(cor);

        if (strcmp(cor, COR) == 0)
        {
            puts("Parabéns! Você acertou :)");
            break;
        }
        else
        {
            if (tentativa == TENTATIVAS)
            {
                puts("Game over!");
            }
            else if (tentativa == (TENTATIVAS-1))
            {
                printf("A cor que estou pensando tem %d caracteres e começa com a letra %c.\n",
                    strlen(COR), COR[0]);
            }
            else
            {
                int diferenca = strlen(cor) - strlen(COR);

                if (diferenca < 0)
                {
                    puts("A cor que estou pensando tem mais caracteres.");
                }
                else if (diferenca == 0)
                {
                    puts("A cor que estou pensando tem este mesma quantidade de caracteres.");
                }
                else
                {
                    puts("A cor que estou pensando tem menos caracteres.");
                }
            }
        }
    }

    return 0;
}







