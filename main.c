#include "headers/includes.h"

int main() {
    TipoApontador labirinto;
	int x, y;

    LeituraArquivo(&labirinto);
	MostrarLabirinto(&labirinto);

	PosicaoEstudante(&labirinto, &x, &y);
    return 0;
}