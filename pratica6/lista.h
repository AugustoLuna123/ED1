#ifndef lista_h
#define lista_h

typedef char Item;

typedef struct celula {
    Item item;
    struct celula *prox;
} TCelula;

typedef struct {
    TCelula *primeiro;
    TCelula *ultimo;
} Lista;

int ListaInicia(Lista* pLista);
int ListaEhVazia(Lista* pLista);
int ListaInserePrimeiro(Lista* pLista, Item item);
int ListaRetiraPrimeiro(Lista* pLista, Item* pItem);
void ListaImprime(Lista* pLista);
void ListaEsvazia(Lista* pLista);

#endif
