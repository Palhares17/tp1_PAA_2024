#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct TipoLabirinto {
    int **labirinto;
    int qtdLinhas, qtdColunas, qtdChaves;
} TipoLabirinto;

typedef TipoLabirinto *TipoApontador;

void LeituraArquivo(TipoApontador labirinto);

#endif