#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct TipoLabirinto {
    int **labirinto;
    int qtdLinhas, qtdColunas, qtdChaves;
} TipoLabirinto;

typedef TipoLabirinto *TipoApontador;

void LeituraArquivo(TipoApontador *lab);
void inicializaLabirinto(TipoApontador *lab, int linha, int coluna, int chave);
void MostrarLabirinto(TipoApontador *lab);
void PosicaoEstudante(TipoApontador *lab, int *posX, int *posY);

#endif