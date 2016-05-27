#include <stdio.h>

#define NUM_NOTAS 3
#define NUM_ALUNOS 5

typedef struct
{
    char nome[32];
    float notas[NUM_NOTAS];
} T_Aluno;

int main()
{
    T_Aluno alunos[NUM_ALUNOS];
    int aluno;

    for (aluno = 0; aluno < NUM_ALUNOS; aluno++)
    {
        int nota;

        printf("--------------------\n");
        printf("ALUNO Nº%d\n", aluno+1);
        printf("--------------------\n");

        printf("Nome: ");
        scanf("%s", alunos[aluno].nome);

        for (nota = 0; nota < NUM_NOTAS; nota++)
        {
            printf("Nota %d: ", nota+1);
            scanf("%f", &(alunos[aluno].notas[nota]));
        }
    }

    for (aluno = 0; aluno < NUM_ALUNOS; aluno++)
    {
        int nota;
        float media = 0;

        for (nota = 0; nota < NUM_NOTAS; nota++)
        {
            media += alunos[aluno].notas[nota];
        }

        media /= NUM_NOTAS;

        printf("--------------------\n");
        printf("ALUNO: %s\n", alunos[aluno].nome);
        printf("MÉDIA: %.1f\n", media);
        printf("--------------------\n");
    }    

    return 0;
}