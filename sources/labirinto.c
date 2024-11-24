#include "../headers/includes.h"

void LeituraArquivo(TipoApontador labirinto) {
    FILE *arq;
    arq = fopen("../arquivos/arquivo1.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    int linhas, colunas, chaves;

    fscanf(arq, "%d %d %d", &linhas, &colunas, &chaves);

    printf("linhas: %d\n", linhas);

    fclose(arq);
}