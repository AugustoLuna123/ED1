#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo *proximo;
} Nodo;

typedef struct Fila {
    Nodo *cabeca;
    Nodo *cauda;
} Fila;

Fila* criar_fila() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->cabeca = NULL;
    fila->cauda = NULL;
    return fila;
}

void enfileirar(Fila *fila, int valor) {
    Nodo *novo_nodo = (Nodo*)malloc(sizeof(Nodo));
    novo_nodo->dado = valor;
    novo_nodo->proximo = NULL;
    if (fila->cauda != NULL) {
        fila->cauda->proximo = novo_nodo;
    }
    fila->cauda = novo_nodo;
    if (fila->cabeca == NULL) {
        fila->cabeca = novo_nodo;
    }
}

int desenfileirar(Fila *fila) {
    if (fila->cabeca == NULL) {
        return -1;
    }
    Nodo *temp = fila->cabeca;
    int valor = temp->dado;
    fila->cabeca = fila->cabeca->proximo;
    if (fila->cabeca == NULL) {
        fila->cauda = NULL;
    }
    free(temp);
    return valor;
}

int fila_vazia(Fila *fila) {
    return fila->cabeca == NULL;
}

void destruir_fila(Fila *fila) {
    while (!fila_vazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}

int main() {
    Fila *fila = criar_fila();
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);

    while (!fila_vazia(fila)) {
        printf("%d\n", desenfileirar(fila));
    }

    destruir_fila(fila);
    return 0;
}
