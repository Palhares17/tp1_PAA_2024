#include "headers/includes.h"

int main() {
    TipoApontador labirinto;
    int x, y;

    LeituraArquivo(&labirinto);

    MovimentaEstudante(&labirinto);

    return 0;
}