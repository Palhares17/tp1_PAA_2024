#include "../headers/includes.h"

int chamadasRecursivas = 0;        // Contador de chamadas recursivas
int nivelMaximoRecursividade = 0;  // Nível máximo de recursividade

void inicializaLabirinto(TipoApontador *lab, int linha, int coluna, int chave) {
    (*lab)->qtdLinhas = linha;
    (*lab)->qtdColunas = coluna;
    (*lab)->qtdChaves = chave;

    (*lab)->labirinto = (int **)calloc(((*lab)->qtdLinhas + 1), sizeof(int *));

    for (int i = 0; i < (*lab)->qtdLinhas; i++) {
        (*lab)->labirinto[i] = (int *)calloc(((*lab)->qtdColunas + 1), sizeof(int));
    }
}

void MostrarLabirinto(TipoApontador *lab) {
    for (int i = 0; i < (*lab)->qtdLinhas; i++) {
        for (int j = 0; j < (*lab)->qtdColunas; j++) {
            if ((*lab)->labirinto[i][j] == 0)
                printf(
                    "\e[0;32m"  // background verde
                    "%d \e[0m",
                    (*lab)->labirinto[i][j]);

            else if ((*lab)->labirinto[i][j] == 1)
                printf(
                    "\e[0;107m"  // background branco
                    "%d \e[0m",
                    (*lab)->labirinto[i][j]);

            else if ((*lab)->labirinto[i][j] == 2)
                printf(
                    "\e[0;104m"  // background azul
                    "%d \e[0m",
                    (*lab)->labirinto[i][j]);

            else if ((*lab)->labirinto[i][j] == 3)
                printf(
                    "\e[0;101m"  // background vermelho
                    "%d \e[0m",
                    (*lab)->labirinto[i][j]);
            else if ((*lab)->labirinto[i][j] == 4)
                printf(
                    "\e[43m"  // background amarelo
                    "%d \e[0m",
                    (*lab)->labirinto[i][j]);
            else if ((*lab)->labirinto[i][j] == 5)
                printf(
                    "\e[45m"  // background rosa
                    "%d \e[0m",
                    (*lab)->labirinto[i][j]);
            else {
                printf("%d", (*lab)->labirinto[i][j]);
            }
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
    int x0, y0;
    int movimentos = 0;

    // Pega a posição inicial do estudante
    getPosicaoEstudante(lab, &x0, &y0);

    // Chama a função recursiva
    if (backtracking(lab, x0, y0, &movimentos, 1)) {
        printf("O estudante se movimentou %d vezes e chegou na linha %d e coluna %d\n", movimentos, x0, y0);
    } else {
        printf("O estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida.\n", movimentos);
    }

    #ifdef MOD_ANALISE
        printf("\n=== MODO ANALISE ===\n");
        printf("Chamadas recursivas: %d\n", chamadasRecursivas);
        printf("Nivel maximo de recursividade: %d\n", nivelMaximoRecursividade);
        printf("====================\n");
     #endif
}

int backtracking(TipoApontador *lab, int linha, int coluna, int *movimentos, int nivelAtual) {
    ImprimirSaidas(lab, linha, coluna);

    #ifdef MOD_ANALISE
        chamadasRecursivas++;  // Incrementa o número de chamadas recursivas
        if (nivelAtual > nivelMaximoRecursividade) {
            nivelMaximoRecursividade = nivelAtual;  // Atualiza o nível máximo
        }
    #endif

    // Movimentos: cima, baixo, esquerda, direita
    int movLinha[] = {-1, 1, 0, 0};
    int movColuna[] = {0, 0, -1, 1};

    // Se chegou na linha 0, o estudante venceu
    if (linha == 0) {
        return 1;
    }

    if (VerificaMatriz(lab, linha, coluna)) {
        if ((*lab)->labirinto[linha][coluna] == 3) {
            (*lab)->labirinto[linha][coluna] = 3;

        } else {
            (*lab)->labirinto[linha][coluna] = 5;  // Marca a posição que permite a passagem
        }
    }

    // Tenta todos os movimentos possíveis
    for (int i = 0; i < 4; i++) {
        int novaLinha = linha + movLinha[i];
        int novaColuna = coluna + movColuna[i];

        // Verifica se é possível avançar
        if (VerificaMatriz(lab, novaLinha, novaColuna)) {
            (*movimentos)++;
            if (backtracking(lab, novaLinha, novaColuna, movimentos, nivelAtual + 1)) {
                return 1;
            }
        }
    }

    // Desmarca a posição antes de retornar
    (*lab)->labirinto[linha][coluna] = 1;
    return 0;
}

int VerificaMatriz(TipoApontador *lab, int linha, int coluna) {
    // Verifica se a posição está dentro dos limites do labirinto
    if (linha >= 0 && linha < (*lab)->qtdLinhas && coluna >= 0 && coluna < (*lab)->qtdColunas) {
        // Verifica se a posição é acessível (1) ou uma porta (3) com chave
        if ((*lab)->labirinto[linha][coluna] == 1) {
            return 1;
        } else if ((*lab)->labirinto[linha][coluna] == 3 && (*lab)->qtdChaves > 0) {
            (*lab)->qtdChaves--;
            return 1;
        } else if ((*lab)->labirinto[linha][coluna] == 4) {  // Pega chave
            (*lab)->qtdChaves++;
            return 1;
        }
    }
    return 0;
}
