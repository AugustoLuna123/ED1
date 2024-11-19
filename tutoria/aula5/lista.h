#ifndef LISTA_h
#define LISTA_H
#include <stdbool.h>

typedef struct lista Lista;
typedef struct item Item;

void criaLista(Lista*);

bool ehVazia(Lista*);

bool inserirItem(Lista*, Item);

bool removeItem(Lista*, int, Item*);

bool buscarItem(Lista*, Item);

bool inverterLista(Lista*);

bool removePares(Lista*);


#endif