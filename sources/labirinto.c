#include "../headers/includes.h"

void inicializaLabirinto(TipoApontador *lab, int linha, int coluna, int chave) {
    (*lab)->qtdLinhas = linha;
    (*lab)->qtdColunas = coluna;
    (*lab)->qtdChaves = chave;

    (*lab)->labirinto = (int **)calloc(((*lab)->qtdLinhas + 1), sizeof(int *));

    for (int i = 0; i < (*lab)->qtdLinhas; i++) {
        (*lab)->labirinto[i] = (int *)calloc(((*lab)->qtdColunas + 1), sizeof(int));
    }
}

void LeituraArquivo(TipoApontador *lab) {
    FILE *arq;
    arq = fopen("./arquivos/arquivo1.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
    }

    int linhas, colunas, chaves;

    fscanf(arq, "%d %d %d", &linhas, &colunas, &chaves);

    inicializaLabirinto(&(*lab), linhas, colunas, chaves);

    char entrada[(*lab)->qtdColunas + 1];

    for (int i = 0; i < (*lab)->qtdLinhas; i++) {
        if (fscanf(arq, "%s", entrada) != 1) {
            printf("Erro ao ler a linha %d do labirinto\n", i);
            fclose(arq);
        }

        // Converte os caracteres da string para inteiros
        for (int j = 0; j < (*lab)->qtdColunas; j++) {
            (*lab)->labirinto[i][j] = entrada[j] - '0';
        }
    }

    fclose(arq);
}

void MostrarLabirinto(TipoApontador *lab) {
    for (int i = 0; i < (*lab)->qtdLinhas; i++) {
        for (int j = 0; j < (*lab)->qtdColunas; j++) {
            if ((*lab)->labirinto[i][j] == 0) printf(
                "\e[0;32m"  // background verde
                "%d \e[0m",
                (*lab)->labirinto[i][j]);

            if ((*lab)->labirinto[i][j] == 1) printf(
                "\e[0;107m"  // background branco
                "%d \e[0m",
                (*lab)->labirinto[i][j]);

            if ((*lab)->labirinto[i][j] == 2) printf(
                "\e[0;104m"  // background azul
                "%d \e[0m",
                (*lab)->labirinto[i][j]);

            if ((*lab)->labirinto[i][j] == 3) printf(
                "\e[0;101m"  // background vermelho
                "%d \e[0m",
                (*lab)->labirinto[i][j]);
        }
        printf("\n");
    }
}

void PosicaoEstudante(TipoApontador *lab, int *posX, int *posY) {
    for (int i = 0; i < (*lab)->qtdLinhas; i++) {
        for (int j = 0; j < (*lab)->qtdColunas; j++) {
            if ((*lab)->labirinto[i][j] == 0) {
                (*posX) = i;
                (*posY) = j;
            }
        }
    }
}

void MovimentaEstudante(TipoApontador *lab) {
    int x0, y0;  // Posição inicial

    PosicaoEstudante(lab, &x0, &y0);

    if (VerificaMatriz(lab, x0, y0)) {
        
    }

    printf("%d %d\n", x0, y0);
}

int VerificaMatriz(TipoApontador *lab, int linha, int coluna) {
    if (linha >= 0 || linha < (*lab)->qtdLinhas && coluna >= 0 || coluna < (*lab)->qtdColunas) {
        printf("Está dentro da matriz\n");

    }
}