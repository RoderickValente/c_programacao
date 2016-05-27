#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NOTAS 3

typedef struct
{
    char* nome;
    float notas[NUM_NOTAS];
} T_Aluno;

int main()
{
    char str[256] = {0};
    T_Aluno* alunos;
    int alunoIdx, qtd_alunos;

    printf("Querido usuário, quantos alunos você quer utilizar? ");
    scanf("%d", &qtd_alunos);
    __fpurge(stdin);

    if (qtd_alunos > 0)
    {
        alunos = (T_Aluno*) malloc(qtd_alunos*sizeof(T_Aluno));

        if (alunos)
        {
            for (alunoIdx = 0; alunoIdx < qtd_alunos; alunoIdx++)
            {
                int nota;
                T_Aluno* aluno = &(alunos[alunoIdx]);

                printf("--------------------\n");
                printf("ALUNO Nº%d\n", alunoIdx+1);
                printf("--------------------\n");

                printf("Nome: ");
                gets(str);

                aluno->nome = (char*) malloc((strlen(str)+1)*sizeof(char));
                if (aluno->nome)
                {
                    strcpy(aluno->nome, str);
                }

                for (nota = 0; nota < NUM_NOTAS; nota++)
                {
                    printf("Nota %d: ", nota+1);
                    scanf("%f", &(aluno->notas[nota]));
                    __fpurge(stdin);
                }
            }

            for (alunoIdx = 0; alunoIdx < qtd_alunos; alunoIdx++)
            {
                int nota;
                float media = 0;
                T_Aluno* aluno = &(alunos[alunoIdx]);

                if (aluno->nome)
                {
                    for (nota = 0; nota < NUM_NOTAS; nota++)
                    {
                        media += aluno->notas[nota];
                    }

                    media /= NUM_NOTAS;

                    printf("--------------------\n");
                    printf("ALUNO: %s\n", aluno->nome);
                    printf("MÉDIA: %.1f\n", media);
                    printf("--------------------\n");

                    free(aluno->nome);
                }
            }

            free(alunos);
        }
    }

    return 0;
}
