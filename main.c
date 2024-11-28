#include "headers/includes.h"

int main() {
    TipoApontador labirinto;
    int x, y;

    int menu;
    printf("Gerar labirinto ou ler de arquivo? (1 - Gerar, 2 - Ler): ");
    scanf("%d", &menu);

    if (menu == 1) {
        gerarLabirinto();
    } else if (LeituraArquivo(&labirinto))
        MovimentaEstudante(&labirinto);

    return 0;
}