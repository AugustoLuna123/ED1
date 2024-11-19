#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int item;
  struct no *prox;
} No;

typedef struct {
  No *pPrimeiro;
  No *pUltimo;
} Lista;

// Exercicio 1
// a) Implemente a função que inicializa uma lista vazia.
void inicializaLista(Lista *l) {
    l->pPrimeiro = NULL;
    l->pUltimo = NULL;
}

// b) Implemente a função que insere um item no final da lista.
bool insere(Lista *l, int item) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
        return false;
    
    novoNo->item = item;
    novoNo->prox = NULL;

    if (l->pPrimeiro == NULL) {
        l->pPrimeiro = novoNo;
        l->pUltimo = novoNo;
    } else {
        l->pUltimo->prox = novoNo;
        l->pUltimo = novoNo;
    }
    
    return true;
}

// c) Implemente a função que imprime os itens da lista.
void imprimirLista(Lista l) {
    No *atual = l.pPrimeiro;
    while (atual != NULL) {
        printf("%d ", atual->item);
        atual = atual->prox;
    }
    printf("\n");
}

// d) Implemente a função que libera a lista
void liberaLista(Lista *l) {
    No *atual = l->pPrimeiro;
    while (atual != NULL) {
        No *aux = atual;
        atual = atual->prox;
        free(aux);
    }
    l->pPrimeiro = NULL;
    l->pUltimo = NULL;
}

// e) Implemente a função que remove um item em qualquer posição da lista.
bool removeItem(Lista *l, int x) {
    No *atual = l->pPrimeiro;
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->item == x) {
            if (anterior == NULL) { // remoção do primeiro elemento
                l->pPrimeiro = atual->prox;
                if (l->pPrimeiro == NULL)
                    l->pUltimo = NULL; // lista ficou vazia
            } else {
                anterior->prox = atual->prox;
                if (atual->prox == NULL)
                    l->pUltimo = anterior; // remoção do último elemento
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return false; // elemento não encontrado
}

// f) Implemente a função que concatena duas listas.
void concatenaListas(Lista *l1, Lista *l2) {
    if (l1->pPrimeiro == NULL) {
        l1->pPrimeiro = l2->pPrimeiro;
    } else {
        l1->pUltimo->prox = l2->pPrimeiro;
    }
    l1->pUltimo = l2->pUltimo;
    l2->pPrimeiro = NULL;
    l2->pUltimo = NULL;
}

// g) Implementar uma função que inverta os nós de uma lista encadeada.
void inverteLista(Lista *l) {
    No *anterior = NULL;
    No *atual = l->pPrimeiro;
    No *proximo;

    l->pUltimo = atual; // novo primeiro será o antigo último

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    l->pPrimeiro = anterior; // novo último será o antigo primeiro
}

int main() {
    Lista listaA;
    Lista listaB;

    inicializaLista(&listaA); // criando lista vazia
    inicializaLista(&listaB); // criando lista vazia

    // inserindo elementos na lista A
    insere(&listaA, 1);
    insere(&listaA, 2);
    insere(&listaA, 3);
    insere(&listaA, 4);
    insere(&listaA, 5);

    // inserindo elementos na lista B
    insere(&listaB, 6);
    insere(&listaB, 7);
    insere(&listaB, 8);
    insere(&listaB, 9);
    insere(&listaB, 10);

    printf("Lista A: ");
    imprimirLista(listaA);
    printf("\n");

    printf("Lista B: ");
    imprimirLista(listaB);
    printf("\n");

    removeItem(&listaA, 2);
    printf("Lista A após remover o item 2: ");
    imprimirLista(listaA);
    printf("\n");

    concatenaListas(&listaA, &listaB);
    printf("Lista A após concatenação com B: ");
    imprimirLista(listaA);
    printf("\n");

    inverteLista(&listaA);
    printf("Lista A após inversão: ");
    imprimirLista(listaA);
    printf("\n");

    liberaLista(&listaA);
    liberaLista(&listaB);

    // Checando se as listas foram liberadas corretamente
    if (listaA.pPrimeiro == NULL && listaA.pUltimo == NULL)
        printf("Listas liberadas com sucesso!\n");
    else
        printf("Erro ao liberar as listas!\n");

    return 0;
}
