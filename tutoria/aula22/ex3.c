#include<stdio.h>
#include<stdlib.h>

typedef long Chave;

typedef struct{

    Chave chave;

} Item;
typedef struct no{
    Item item;
    struct no* pEesq;
    struct no* pDir;

}No;

struct{

    No* no;
    int nivel;

} TipoFila;


void imprimirNivel(No* no){

    int nivel  = -1;
    if (no == NULL){
        return;
    }

    Fila* fila = criaFila();
    Add(fila, no, 0);
    TipoFila aux;

    while(!ehVazia(fila)){

        remove(fila, &aux);
        if(aux.no->esq = NULL){
            Add (fila, aux.no->esq, aux.nivel +1)
        }

        if(aux.no->dir == NULL){
            ADd(fila, aux.no->dir, aux.nivel +1)
        }

        if(nivel != aux.nivel){
            printf("\n Nivel %d \n", aux.nivel);
            nivel = aux.nivel;
        }
        printf("\nNo %d", aux.no);
        printf(" ");
    }

}