#include "../headers/includes.h"

int LeituraArquivo(TipoApontador *lab) {
    FILE *arq;
    char nomeArq[40];

    printf("Escolha um arquivo de leitura? ");
    scanf("%s", nomeArq);

    char caminhoArq[40] = "./arquivos/";

    strcat(caminhoArq, nomeArq);

    arq = fopen(caminhoArq, "r");

    if (arq == NULL) {
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

void ImprimirSaidas(TipoApontador *lab, int linha, int coluna) {
    printf("Linha: %d Coluna: %d\n", linha, coluna);

    MostrarLabirinto(lab);
}