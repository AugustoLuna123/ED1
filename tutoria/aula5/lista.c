#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

#define INICIO 0
#define MAXTAM 1000

struct item{
    int chave;
};

struct lista{
    Item item[MAXTAM];
    int primeiro;
    int ultimo;
};

// Complexidade de tempo: O(1)
void criaLista(Lista* lista){
    lista->primeiro = INICIO;
    lista->ultimo = lista->primeiro;
}

// Complexidade de tempo: O(1)
bool ehVazia(Lista* lista){
    if(lista->ultimo == lista->primeiro){
        return true;
    }
    else return false;
}

// Complexidade de tempo: O(1)
bool inserirItem(Lista* lista, Item item){
    if(lista->ultimo == MAXTAM){
        return false;
    } else
    lista->item[lista->ultimo++] = item;
    return true;
}

// Complexidade de tempo: O(n)
bool removeItem(Lista* lista, int p, Item* item){
    int cont;
    if(ehVazia(lista) == true || p >= lista->ultimo){
        return false;
    } else
    *item = lista->item[p];
    lista->ultimo--;
    for(cont = p+1; cont <= lista->ultimo; cont++){
        lista->item[cont-1] = lista->item[cont];
    }
    return true;    
}

// Complexidade de tempo: O(n)
bool buscarItem(Lista* lista, Item item){
    for (int i = lista->primeiro; i < lista->ultimo; i++) {
        if (lista->item[i].chave == item.chave) {
            return true;
        }
    }
    return false;
}

// Complexidade de tempo: O(n)
bool inverterLista(Lista *lista) {
    if (lista->primeiro == lista->ultimo) {
        return false; 
    }
    int i = lista->primeiro;
    int j = lista->ultimo - 1;
    while (i < j) {
        Item temp = lista->item[i];
        lista->item[i] = lista->item[j];
        lista->item[j] = temp;
        i++;
        j--;
    }
    return true;
}

// Complexidade de tempo: O(n), onde n é o número de elementos na lista
bool removePares(Lista *lista) {
    int novoUltimo = lista->primeiro;
    for (int i = lista->primeiro; i < lista->ultimo; i++) {
        if (lista->item[i].chave % 2 != 0) {
            lista->item[novoUltimo] = lista->item[i];
            novoUltimo++;
        }
    }
    if (novoUltimo == lista->ultimo) {
        return false;
    }
    lista->ultimo = novoUltimo;
    return true;
}
