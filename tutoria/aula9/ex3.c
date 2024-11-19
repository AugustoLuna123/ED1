#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct Lista {
    No *ultimo;
} Lista;

void unir(Lista *L1, Lista *L2) {
    if (L1->ultimo == NULL) {
        L1->ultimo = L2->ultimo;
    } else if (L2->ultimo != NULL) {
        No *primeiro_L2 = L2->ultimo->prox;
        L2->ultimo->prox = L1->ultimo->prox;
        L1->ultimo->prox = primeiro_L2;
        L1->ultimo = L2->ultimo;
    }
    L2->ultimo = NULL;
}

void adicionar(Lista *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;

    if (lista->ultimo == NULL) {
        lista->ultimo = novo;
        novo->prox = novo;
    } else {
        novo->prox = lista->ultimo->prox;
        lista->ultimo->prox = novo;
        lista->ultimo = novo;
    }
}

void imprimir(Lista *lista) {
    if (lista->ultimo == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->ultimo->prox;
    do {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while (atual != lista->ultimo->prox);

    printf("\n");
}

int main() {
    Lista L1 = {NULL};
    Lista L2 = {NULL};

    adicionar(&L1, 1);
    adicionar(&L1, 2);
    adicionar(&L1, 3);

    adicionar(&L2, 4);
    adicionar(&L2, 5);
    adicionar(&L2, 6);

    imprimir(&L1);
    imprimir(&L2);

    unir(&L1, &L2);

    imprimir(&L1);
    imprimir(&L2);

    return 0;
}
