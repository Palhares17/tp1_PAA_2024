#include "headers/includes.h"

int main() {
    TipoApontador labirinto;
    int x, y;

    if (LeituraArquivo(&labirinto)) MovimentaEstudante(&labirinto);   

    return 0;
}