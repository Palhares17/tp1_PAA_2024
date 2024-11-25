#include "../headers/includes.h"

void inicializaLabirinto(TipoApontador *lab, int linha, int coluna, int chave) {
    (*lab)->qtdLinhas = linha;
    (*lab)->qtdColunas = coluna;
    (*lab)->qtdChaves = chave;

    (*lab)->labirinto = (int **)calloc(((*lab)->qtdLinhas + 1), sizeof(int *));

    for (int i = 0; i < (*lab)->qtdLinhas; i++) {
        (*lab)->labirinto[i] = (int *)calloc(((*lab)->qtdColunas + 1), sizeof(int));
    }

    return;
}

void LeituraArquivo(TipoApontador *lab) {
    FILE *arq;
    arq = fopen("./arquivos/arquivo1.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    int linhas, colunas, chaves;

    fscanf(arq, "%d %d %d", &linhas, &colunas, &chaves);

    inicializaLabirinto(&(*lab), linhas, colunas, chaves);

    int entrada;

    for (int i = 0; i < ((*lab)->qtdLinhas); i++) {
        fscanf(arq, "%d", &entrada);
        printf("valor = %d ", entrada);

        printf("\n");
    }

    fclose(arq);
}