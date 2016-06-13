typedef struct S_Recorde
{
    char* nome;
    unsigned int pontuacao;
    struct S_Recorde* prox;
} T_Recorde;

#define MAX_RECORDES 10

/* Retorna 0 se não for recorde ou número de 1 a MAX_RECORDES */
int numero_recorde(unsigned int pontuacao);

/* Adiciona um recorde no ranking */
void inserir_recorde(char* nome, unsigned int pontuacao);

/* Retorna ponteiro para primeiro recorde e quantidade de recordes em qtd */
T_Recorde* obter_ranking();

/* Destrói um ranking obtido em obter_ranking */
void destruir_ranking(T_Recorde* ranking);
