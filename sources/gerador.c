#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headers/includes.h"

void gerarLabirinto() {
    char nomeArq[100];
    int linhas, colunas, chaves;

    printf("Digite o nome do arquivo (com .txt no final): ");
    scanf("%s", nomeArq);

    char caminhoArq[40] = "./arquivos/";
    strcat(caminhoArq, nomeArq);
    limpaTela();
    printf("\nDigite o numero de linhas, colunas e chaves do labirinto (Ex.: 5 5 2): ");
    scanf("%d %d %d", &linhas, &colunas, &chaves);

    FILE *arquivo = fopen(caminhoArq, "w");

    if (arquivo == NULL) {
        limpaTela();
        printf("Erro ao criar o arquivo!\n");
        return;
    }

    fprintf(arquivo, "%d %d %d\n", linhas, colunas, chaves);

    srand(time(NULL));

    // Aloca memória para o labirinto
    int **labirinto = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        labirinto[i] = (int *)calloc(colunas, sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if ((rand() % 10) < 2) {  // 20% de chance para chave
                labirinto[i][j] = 3;

            } else if ((rand() % 10) < 1) {  // 10% de chance para `4`
                labirinto[i][j] = 4;

            } else {
                labirinto[i][j] = (rand() % 10) < 7 ? 1 : 2;  // 70% para `1`, 30% para `2`
            }
        }
    }

    int pos = colunas / 2;
    labirinto[linhas - 1][pos] = 0;  // Marca a posição inicial como `0`

    printf("%d\n", labirinto[linhas - 1][pos]);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fprintf(arquivo, "%d", labirinto[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    // Libera a memória alocada
    for (int i = 0; i < linhas; i++) {
        free(labirinto[i]);
    }
    free(labirinto);

    fclose(arquivo);

    printf("Arquivo '%s' criado com sucesso com o labirinto gerado!\n", nomeArq);
}
