#include "headers/includes.h"

int main() {
    TipoApontador labirinto;
    int x, y;

    LeituraArquivo(&labirinto);

    MostrarLabirinto(&labirinto);

    MovimentaEstudante(&labirinto);

    MostrarLabirinto(&labirinto);

    return 0;
}