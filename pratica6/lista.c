#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int ListaInicia(Lista* pLista) {
    pLista->primeiro = NULL;
    pLista->ultimo = NULL;
    return 1;
}

int ListaEhVazia(Lista* pLista) {
    return pLista->primeiro == NULL;
}

int ListaInserePrimeiro(Lista* pLista, Item item) {
    TCelula* nova = (TCelula*) malloc(sizeof(TCelula));
    if (nova == NULL)
        return 0;
    
    nova->item = item;
    nova->prox = pLista->primeiro;
    pLista->primeiro = nova;

    if (pLista->ultimo == NULL)
        pLista->ultimo = nova;

    return 1;
}

int ListaRetiraPrimeiro(Lista* pLista, Item* pItem) {
    if (ListaEhVazia(pLista))
        return 0;

    *pItem = pLista->primeiro->item;
    TCelula* temp = pLista->primeiro;
    pLista->primeiro = pLista->primeiro->prox;
    free(temp);

    if (pLista->primeiro == NULL)
        pLista->ultimo = NULL;

    return 1;
}

void ListaImprime(Lista* pLista) {
    TCelula* atual = pLista->primeiro;
    while (atual != NULL) {
        printf("%c ", atual->item);
        atual = atual->prox;
    }
    printf("\n");
}

void ListaEsvazia(Lista* pLista) {
    TCelula* atual = pLista->primeiro;
    while (atual != NULL) {
        TCelula* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    pLista->primeiro = NULL;
    pLista->ultimo = NULL;
}
    