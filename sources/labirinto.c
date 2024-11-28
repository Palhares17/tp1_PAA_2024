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
            if ((*lab)->labirinto[i][j] == 5) printf(
                "\e[45m"  // background vermelho
                "%d \e[0m",
                (*lab)->labirinto[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void getPosicaoEstudante(TipoApontador *lab, int *posX, int *posY) {
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
    int x0, y0;          // Posição inicial
    int movimentos = 0;  // Contador de movimentos

    // Pega a posição inicial do estudante
    getPosicaoEstudante(lab, &x0, &y0);

    // Chama a função recursiva
    if (backtracking(lab, x0, y0, &movimentos)) {
        printf("O estudante se movimentou %d vezes e chegou na linha 0.\n", movimentos);
    } else {
        printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida.\n", movimentos);
    }
}

int backtracking(TipoApontador *lab, int linha, int coluna, int *movimentos) {
    MostrarLabirinto(lab);
    // Movimentos: cima, baixo, esquerda, direita
    int movLinha[] = {-1, 1, 0, 0};
    int movColuna[] = {0, 0, -1, 1};

    // Se chegou na linha 0, o estudante venceu
    if (linha == 0) {
        printf("Linha: %d Coluna: %d\n", linha, coluna);
        return 1;  // Sucesso
    }

    if (VerificaMatriz(lab, linha, coluna)) {
        if ((*lab)->labirinto[linha][coluna] == 3) {
            (*lab)->labirinto[linha][coluna] = 3;

        } else if ((*lab)->labirinto[linha][coluna] == 0) {
            (*lab)->labirinto[linha][coluna] = 0;

        } else {
            (*lab)->labirinto[linha][coluna] = 5;
        }
    }

    // Tenta todos os movimentos possíveis
    for (int i = 0; i < 4; i++) {
        int novaLinha = linha + movLinha[i];
        int novaColuna = coluna + movColuna[i];

        // Verifica se é possível avançar
        if (VerificaMatriz(lab, novaLinha, novaColuna)) {
            (*movimentos)++;  // Incrementa o número de movimentos
            if (backtracking(lab, novaLinha, novaColuna, movimentos)) {
                return 1;  // Sucesso
            }
            (*movimentos)--;  // Retrocede
        }
    }

    // Desmarca a posição antes de retornar
    (*lab)->labirinto[linha][coluna] = 1;
    return 0;  // Caminho sem sucesso
}

int VerificaMatriz(TipoApontador *lab, int linha, int coluna) {
    // Verifica se a posição está dentro dos limites do labirinto
    if (linha >= 0 && linha < (*lab)->qtdLinhas && coluna >= 0 && coluna < (*lab)->qtdColunas) {
        // Verifica se a posição é acessível (1) ou uma porta (3) com chave
        if ((*lab)->labirinto[linha][coluna] == 1) {
            return 1;  // Pode avançar
        } else if ((*lab)->labirinto[linha][coluna] == 3 && (*lab)->qtdChaves > 0) {
            (*lab)->qtdChaves--;  // Usa uma chave
            return 1;             // Pode avançar
        }
    }
    return 0;  // Não pode avançar
}
