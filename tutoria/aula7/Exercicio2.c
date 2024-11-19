#include <stdio.h>
#include <stdbool.h>

#define MAXTAM 1000

typedef struct {
    int n;           
    int vet[MAXTAM]; 
} Pilha;

Pilha* PilhaInicia() { //O(1)
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->n = 0; 
    }
    return p;
}

bool PilhaEhVazia(Pilha *p) { // O(1)
    return (p->n == 0);
}

bool PilhaPush(Pilha *p, int chave) { //O(1)
    if (p->n >= MAXTAM) {
        return false; 
    }
    p->vet[p->n] = chave; 
    p->n++;
    return true;
}

bool PilhaPop(Pilha *p, int *chave) { // O(1)
    if (PilhaEhVazia(p)) {
        return false; 
    }
    p->n--; 
    *chave = p->vet[p->n]; 
    return true;
}

void PilhaLibera(Pilha **p) { //O(1)
    if (p != NULL && *p != NULL) {
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
