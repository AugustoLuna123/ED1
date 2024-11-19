#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

// função que cria uma nova matriz esparsa
MatrizEsparsa* criarMatrizEsparsa(int dimensao) {
    MatrizEsparsa *matriz = (MatrizEsparsa *)malloc(sizeof(MatrizEsparsa)); 
    matriz->dimensao = dimensao; // define a dimensão da matriz
    matriz->primeira = NULL; // inicializa a lista de células como vazia
    return matriz; 
}

// função que libera a memória alocada para a matriz esparsa
void liberarMatrizEsparsa(MatrizEsparsa *matriz) {
    Celula *atual = matriz->primeira; // começa pela primeira célula da lista
    while (atual != NULL) {
        Celula *temp = atual; // guarda a célula atual
        atual = atual->prox; // avança para a próxima célula
        free(temp); 
    }
    free(matriz); 
}

// função que insere um elemento na matriz esparsa
void inserirElemento(MatrizEsparsa *matriz, int linha, int coluna, int valor) {
    if (valor == 0){ // se o valor for 0 não armazena
         return; 
    }
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->linha = linha; // define a linha da célula
    nova->coluna = coluna; // define a coluna da célula
    nova->valor = valor; // define o valor da célula
    nova->prox = matriz->primeira; //faz a nova célula apontar para a primeira célula da lista
    matriz->primeira = nova; // atualiza a primeira célula da lista para a nova célula
}

// função que obtém o valor de um elemento da matriz esparsa
int obterElemento(MatrizEsparsa *matriz, int linha, int coluna) {
    Celula *atual = matriz->primeira; // começa pela primeira célula da lista
    while (atual != NULL) {
        if (atual->linha == linha && atual->coluna == coluna) {
            return atual->valor; // retorna o valor se encontrar a célula na posição (linha, coluna)
        }
        atual = atual->prox; // avança para a próxima célula
    }
    return 0; // retorna 0 se a célula não for encontrada (valor padrão para elementos não armazenados)
}


// função que imprime a matriz esparsa como uma matriz bidimensional
void imprimirMatrizEsparsa(MatrizEsparsa *matriz) {
    for (int i = 0; i < matriz->dimensao; i++) { 
        for (int j = 0; j < matriz->dimensao; j++) { 
            printf("%d ", obterElemento(matriz, i, j)); 
        }
        printf("\n"); 
    }
}
