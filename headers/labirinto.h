#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct TipoLabirinto {
    int **labirinto;
    int qtdLinhas, qtdColunas, qtdChaves;
} TipoLabirinto;

typedef TipoLabirinto *TipoApontador;

int LeituraArquivo(TipoApontador *lab);
void inicializaLabirinto(TipoApontador *lab, int linha, int coluna, int chave);
void MostrarLabirinto(TipoApontador *lab);
void getPosicaoEstudante(TipoApontador *lab, int *posX, int *posY);
void MovimentaEstudante(TipoApontador *lab);
int backtracking(TipoApontador *lab, int linha, int coluna, int *movimentos, int nivelAtual);
int VerificaMatriz(TipoApontador *lab, int linha, int coluna);

void ImprimirSaidas(TipoApontador *lab, int linha, int coluna);

void gerarLabirinto();

#endif