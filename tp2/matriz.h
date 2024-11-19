#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Celula {
    int linha, coluna;
    int valor;
    struct Celula *prox;
} Celula;

typedef struct {
    int dimensao;
    Celula *primeira;
} MatrizEsparsa;

MatrizEsparsa* criarMatrizEsparsa(int dimensao);
void liberarMatrizEsparsa(MatrizEsparsa *matriz);
void inserirElemento(MatrizEsparsa *matriz, int linha, int coluna, int valor);
int obterElemento(MatrizEsparsa *matriz, int linha, int coluna);
void imprimirMatrizEsparsa(MatrizEsparsa *matriz);

#endif
