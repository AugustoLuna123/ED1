#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para criar a árvore BST
void criar(No** no) {
    *no = NULL;
}

// Função para destruir a árvore BST (libera a memória de todos os nós)
void destruir(No** no) {
    if (*no != NULL) {
        destruir(&((*no)->esq));
        destruir(&((*no)->dir));
        free(*no);
        *no = NULL;
    }
}

// Função auxiliar para criar um novo nó
No* criar_no(Item item) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->itens[0] = item;
        novo->n = 1;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

// Função para inserir um preço na árvore
bool inserir(No** no, Item item) {
    if (*no == NULL) {
        *no = criar_no(item);
        return true;
    }

    if ((*no)->n < 10 && item.preco == (*no)->itens[0].preco) {
        (*no)->itens[(*no)->n] = item;
        (*no)->n++;
        return true;
    }

    if (item.preco < (*no)->itens[0].preco)
        return inserir(&((*no)->esq), item);
    else
        return inserir(&((*no)->dir), item);
}

// Função auxiliar para imprimir o conteúdo formatado de um nó
void imprimeNo(No* no) {
    printf("%d ( ", no->itens[0].preco);
    for (int i = 0; i < no->n; i++) {
        printf("[%s|%s] ", no->itens[i].cultura, no->itens[i].fazenda);
    }
    printf(")\n");
}

// Função para imprimir a árvore em ordem (InOrder)
void imprimeIn(No* no, int a, int b) {
    if (no != NULL) {
        imprimeIn(no->esq, a, b);
        if (no->itens[0].preco >= a && no->itens[0].preco <= b) {
            imprimeNo(no);
        }
        imprimeIn(no->dir, a, b);
    }
}

// Função para imprimir a árvore em pré-ordem (PreOrder)
void imprimePre(No* no, int a, int b) {
    if (no != NULL) {
        if (no->itens[0].preco >= a && no->itens[0].preco <= b) {
            imprimeNo(no);
        }
        imprimePre(no->esq, a, b);
        imprimePre(no->dir, a, b);
    }
}

// Função para imprimir a árvore em pós-ordem (PosOrder)
void imprimePos(No* no, int a, int b) {
    if (no != NULL) {
        imprimePos(no->esq, a, b);
        imprimePos(no->dir, a, b);
        if (no->itens[0].preco >= a && no->itens[0].preco <= b) {
            imprimeNo(no);
        }
    }
}
