#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Item;

typedef struct cel {
    Item item;
    struct cel *prox;
} Celula;

typedef struct {
    Celula *cabeca;
} Pilha;

Pilha *PilhaInicia() { // O(1)
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->cabeca = NULL;
    }
    return p;
}

bool PilhaEhVazia(Pilha *p) { // O(1)
    return (p == NULL || p->cabeca == NULL);
}


bool PilhaPush(Pilha *p, int chave) { // O(1)
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    if (nova == NULL) {
        return false; 
    }
    nova->item.chave = chave;
    nova->prox = p->cabeca;
    p->cabeca = nova;
    return true;
}

bool PilhaPop(Pilha *p, int *chave) { // O(1)
    if (PilhaEhVazia(p)) {
        return false; 
    }
    Celula *topo = p->cabeca;
    *chave = topo->item.chave;
    p->cabeca = topo->prox;
    free(topo);
    return true;
}

void PilhaLibera(Pilha **p) { // O(n)
    if (p != NULL && *p != NULL) {
        Celula *atual = (*p)->cabeca;
        while (atual != NULL) {
            Celula *prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(*p);
        *p = NULL;
    }
}

bool InvertePilha(Pilha *p) { // O(n)
    Pilha *aux = PilhaInicia();
    if (aux == NULL) {
        return false;
    }
    
    int chave;
    while (!PilhaEhVazia(p)) {
        PilhaPop(p, &chave);
        PilhaPush(aux, chave);
    }
    
    while (!PilhaEhVazia(aux)) {
        PilhaPop(aux, &chave);
        PilhaPush(p, chave);
    }
    
    PilhaLibera(&aux);
    return true;
}

int main() {
    Pilha *pilha = PilhaInicia();
    
    PilhaPush(pilha, 10);
    PilhaPush(pilha, 20);
    PilhaPush(pilha, 30);
    
    InvertePilha(pilha);
    
    int chave;
    while (PilhaPop(pilha, &chave)) {
        printf("%d ", chave); 
    }
    printf("\n");
    
    PilhaLibera(&pilha);
    
    return 0;
}
