#include "headers/includes.h"

int main() {
    TipoApontador labirinto;
    int x, y;

    printf("\n\n========== Inicio da fuga ==========\n\n");

    while (1) {
        int menu;
        printf("\n\nSelecione uma dessas opcoes:\n");
        printf("------------------------------\n");
        printf(
            "(1) Gerar um novo arquivo de dados.\n\n"
            "(2) Ler e exibir arquivo ja criado.\n\n"
            "(3) ou qualquer outro caracter: Sair do programa.\n\n\n"
            "Digite um numero: ");

        scanf("%d", &menu);

        printf("\n\n");

        printf("\n==============================\n");

        if (menu == 1) {
            limpaTela();
            gerarLabirinto();

        } else if (menu == 2) {
            limpaTela();
            if (LeituraArquivo(&labirinto))
                MovimentaEstudante(&labirinto);

        } else {
            limpaTela();
            break;
        }
    }

    return 0;
}