#include <stdio.h>

int main(int argc, char* argv[])
{
    int alunos, exames;
    int idx_aluno, idx_exame;

    printf("Quantidade de alunos: ");
    scanf("%d", &alunos);
    printf("Quantidade de exames: ");
    scanf("%d", &exames);

    for (idx_aluno = 0; idx_aluno < alunos; idx_aluno++)
    {
        float media = 0;

        for (idx_exame = 0; idx_exame < exames; idx_exame++)
        {
            float nota1, nota2;

            printf("Digite a nota do exame teórico: ");
            scanf("%f", &nota1);
            printf("Digite a nota do seminário: ");
            scanf("%f", &nota2);

            media += (nota1 * 0.8 + nota2 * 0.2);
        }

        printf("Média: %.2f\n\n", media/exames);
    }

    return 0;
}