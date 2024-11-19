#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "lista.h"

bool listaInicia(Lista* plista){
    plista->pPrimeiro = (Celula*)malloc(sizeof(Celula));
     if(plista->pPrimeiro == NULL){
        return false;
    } 

    plista->pPrimeiro = plista->pPrimeiro;
    plista->pPrimeiro->pProx = NULL;

    return true;
}

bool listaEhVazia(Lista* pLista){
    return (pLista->pPrimeiro == NULL);
}

bool listaInsereInicio(Lista* pLista, Item item){
    pLista->pPrimeiro->pProx = (Celula*)malloc(sizeof(Celula));
    if(pLista->pPrimeiro->pProx == NULL){
        return false;
    }

    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    pLista->pPrimeiro->item = item;
    pLista->pPrimeiro->pProx = NULL;
    
    return true;
}   

bool listaRemoveInicio(Lista* pLista, Item* pitem){
    if(listaEhVazia(pLista)){
        return false;
    }

    *pitem = pLista->pPrimeiro->item;

    Celula* temporario = pLista->pPrimeiro;
    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    free(temporario);

    if(pLista->pPrimeiro == NULL){
        return true;
    }

    
}