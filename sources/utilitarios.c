#include "../headers/includes.h"

int LeituraArquivo(TipoApontador *lab) {
    FILE *arq;
    char nomeArq[40];
    limpaTela();
    printf("Escolha um arquivo de leitura (Digite o nome do arquivo com .txt): ");
    scanf("%s", nomeArq);

    char caminhoArq[40] = "./arquivos/";

    strcat(caminhoArq, nomeArq);

    arq = fopen(caminhoArq, "r");

    if (arq == NULL) {
        limpaTela();
        printf("Erro ao abrir o arquivo\n");
        printf("Nao foi encontrado o arquivo %s\n", caminhoArq);
        return 0;

    } else {
        int linhas, colunas, chaves;

        fscanf(arq, "%d %d %d", &linhas, &colunas, &chaves);

        inicializaLabirinto(lab, linhas, colunas, chaves);

        char entrada[(*lab)->qtdColunas + 1];

        for (int i = 0; i < (*lab)->qtdLinhas; i++) {
            if (fscanf(arq, "%s", entrada) != 1) {
                printf("Erro ao ler a linha %d do labirinto\n", i);
                fclose(arq);
            }

            // Converte os caracteres da string para inteiros
            for (int j = 0; j < (*lab)->qtdColunas; j++) {
                (*lab)->labirinto[i][j] = entrada[j] - '0';
            }
        }

        fclose(arq);
        return 1;
    }
}

void limpaTela() {
#ifdef _WIN32       // Verifica se o sistema é Windows
    system("cls");  // Limpa a tela no Windows
#else
    system("clear");  // Limpa a tela no Linux/Mac
#endif
}

void ImprimirSaidas(TipoApontador *lab, int linha, int coluna) {
    printf("Posicao atual:\n");
    printf("Linha: %d Coluna: %d\n", linha, coluna);
    printf("\n====== Labirinto ======\n\n");

    MostrarLabirinto(lab);
}