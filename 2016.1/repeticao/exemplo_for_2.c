#include <stdio.h>

#define TENTATIVAS 3
#define USUARIO 666
#define SENHA 666

int main(int argc, char* argv[])
{
    char logado = 0;
    int usuario, senha;
    int tentativa;

    for (tentativa = 1; tentativa <= TENTATIVAS; tentativa++)
    {
        printf("Usuário: ");
        scanf("%d", &usuario);
        printf("Senha  : ");
        scanf("%d", &senha);

        if ((usuario == USUARIO) && (senha == SENHA))
        {
            logado = 1;
            break;
        }

        if (tentativa < TENTATIVAS)
            puts("Dados incorretos! Por favor, tente novamente.");
    }

    if (!logado)
    {
        puts("Número máximo de tentativas excedido! Sai pra lá, satanás!");
    } 
    else
    {
        char opcao;

        /* Chegou aqui, o brother acertou o usuário e a senha */
        puts("1 - Cadastrar aluno");
        puts("2 - Buscar aluno");
        puts("3 - Excluir aluno");
        puts("4 - Sair");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: puts("Entrou em cadastrar..."); break;
            case 2: puts("Entrou em buscar..."); break;
            case 3: puts("Entrou em excluir..."); break;
            case 4: puts("Vlw flw..."); break;
            default: puts("Eim?!");
        }
    }

    return 0;
}