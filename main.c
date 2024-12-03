#include "headers/includes.h"

int main() {
    TipoApontador labirinto;
    int x, y;

    while(1) {
        int menu;
        
        printf("1)Gerar um novo arquivo de dados.\n2)Ler e exibir arquivo ja criado.\n3 ou qualquer outro caracter) Sair do programa.\nDigite um numero: ");
        scanf("%d", &menu);
        
        if (menu == 1) {
            limpaTela();
            gerarLabirinto();
        
        } else if (menu == 2){
            limpaTela();
            if(LeituraArquivo(&labirinto))
                MovimentaEstudante(&labirinto);
        
        } else{
            limpaTela();
            break;
        }

    }
    

    return 0;
}