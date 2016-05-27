#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NOTAS 3

typedef struct
{
    char* nome;
    float notas[NUM_NOTAS];
} T_Aluno;

void* meu_malloc(int size)
{
    void* m = malloc(size);
    printf("[MALLOC] %d %p\n", size, m);
    return m;
}

void* meu_realloc(void* p, int size)
{
    void* m = realloc(p, size);
    printf("[REALLOC] %p %d %p\n", p, size, m);
    return m;
}

void meu_free(void* p)
{
    free(p);
    printf("[FREE] %p\n", p);
}

int main()
{
    char str[256] = {0};
    T_Aluno* alunos = 0;
    char opcao;
    int alunoIdx, qtd_alunos = 0;

    do
    {
        int nota;
        T_Aluno* aluno;

        qtd_alunos++;
        alunos = (T_Aluno*) meu_realloc(alunos, qtd_alunos * sizeof(T_Aluno));
        aluno = &(alunos[qtd_alunos-1]);

        printf("--------------------\n");
        printf("ALUNO Nº%d\n", qtd_alunos);
        printf("--------------------\n");

        printf("Nome: ");
        gets(str);

        aluno->nome = (char*) meu_malloc((strlen(str)+1)*sizeof(char));
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

        printf("Deseja inserir outro aluno (S/N)? ");
        scanf("%c", &opcao);
        __fpurge(stdin);
    } while (opcao != 'N');

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

            meu_free(aluno->nome);
        }
    }

    meu_free(alunos);

    return 0;
}
