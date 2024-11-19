#ifndef lista_h
#define lista_h

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int chave;
} Item;

typedef struct celula {
    struct celula *pProx;
    Item item;
} Celula;
     
typedef struct {
    Celula *pPrimeiro;
} Lista;

typedef Lista Pilha;

bool listaInicia(Lista*);

bool listaEhVazia(Lista*);

bool listaInsereInicio(Lista*, Item);

bool listaRemoveInicio(Lista*, Item* );


#endif