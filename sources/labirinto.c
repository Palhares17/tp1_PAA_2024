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

    char entrada[(*lab)->qtdColunas + 1];

    for (int i = 0; i < (*lab)->qtdLinhas; i++) {
        if (fscanf(arq, "%s", entrada) != 1) {
            printf("Erro ao ler a linha %d do labirinto\n", i);
            fclose(arq);
            exit(1);
        }

        // Converte os caracteres da string para inteiros
        for (int j = 0; j < (*lab)->qtdColunas; j++) {
            (*lab)->labirinto[i][j] = entrada[j] - '0';
            printf("%d ", (*lab)->labirinto[i][j]);
        }
        printf("\n");
    }

    fclose(arq);
}