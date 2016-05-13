#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

typedef unsigned char byte;

typedef struct S_Aluno
{
    char nome[64];
    byte idade;
    byte genero;
} T_Aluno;

int main()
{
    T_Aluno alunos[2];
    byte idx;

    for (idx = 0; idx < 2; idx++)
    {
        printf("ALUNO %d\n--------------\n", idx+1);
        printf("Nome: ");
        scanf("%s", alunos[idx].nome);
        printf("Idade: ");
        scanf("%d", (int*) &(alunos[idx].idade));
        printf("Gênero: ");
        __fpurge(stdin);
        scanf("%c", &(alunos[idx].genero));
    }
    

    printf("MINHAS ESTRUTURAS BOLADAS:\n\n");

    for (idx = 0; idx < 2; idx++)
    {
        printf("ALUNO %d\n--------------\n", idx+1);
        printf("Nome: %s\nIdade: %i\nGênero: %c\n", alunos[idx].nome, alunos[idx].idade, alunos[idx].genero);
    }

    

    return 0;
}
