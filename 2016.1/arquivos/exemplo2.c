#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef unsigned char bool;

typedef struct
{
    char* nome;
    unsigned char idade;
} T_Pessoa;

bool le_arquivo(T_Pessoa* pessoa)
{
    bool result = false;
    FILE* arquivo = fopen("exemplo1", "r");

    if (arquivo)
    {
        char ch = 0;
        int idx = 0;

        do {
            ch = fgetc(arquivo);

            if (ch != ',')
            {
                pessoa->nome = (char*) realloc(pessoa->nome,
                    (idx+1) * sizeof(char));
                pessoa->nome[idx++] = ch;
            }
            else
            {
                pessoa->nome = (char*) realloc(pessoa->nome,
                    (idx+1) * sizeof(char));
                pessoa->nome[idx] = '\0';
                break;
            }
        } while (ch != EOF);

        if (ch != EOF)
        {
            fscanf(arquivo, "%u", &(pessoa->idade));
        }

        fclose(arquivo);
    }

    return result;
}

int main()
{
    T_Pessoa pessoa = {0};

    le_arquivo(&pessoa);
    printf("Nome lido: %s\n", pessoa.nome);
    printf("Idade lida: %d\n", pessoa.idade);

    free(pessoa.nome);

    return 0;
}

