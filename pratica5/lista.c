#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Inicia as variáveis da lista
void ListaInicia(Lista *pLista) {
    pLista->pPrimeiro = (Celula*)malloc(sizeof(Celula));
    pLista->pPrimeiro->pProx = NULL;
    pLista->pUltimo = pLista->pPrimeiro;
}

// Retorna se a lista está vazia
bool ListaEhVazia(Lista *pLista) {
    return (pLista->pPrimeiro->pProx == NULL);
}

// Insere um item no final da lista
bool ListaInsereFinal(Lista *pLista, Item x) {
    pLista->pUltimo->pProx = (Celula*)malloc(sizeof(Celula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL;
    return true;
}

// Retira o primeiro item da lista
bool ListaRetiraPrimeiro(Lista *pLista, Item *pX) {
    Celula *pAux;
    if (ListaEhVazia(pLista)) {
        return false;
    }
    pAux = pLista->pPrimeiro->pProx;
    *pX = pAux->item;
    pLista->pPrimeiro->pProx = pAux->pProx;
    free(pAux);
    return true;
}

// Imprime os elementos da lista
void ListaImprime(Lista *pLista) {
    Celula *pAux = pLista->pPrimeiro->pProx;
    while (pAux != NULL) {
        printf("%c", pAux->item.letra);
        pAux = pAux->pProx;
    }
}

// Remove cada elemento de uma lista e libera a memória
void ListaEsvazia(Lista *pLista) {
    Item temp;
    while (!ListaEhVazia(pLista)) {
        ListaRetiraPrimeiro(pLista, &temp);
    }
}

// Acrescenta o conteúdo de uma lista ao final de outra, apenas manipulando ponteiros
void ListaInclude(Lista *pLista1, Lista *pLista2) {
    if (!ListaEhVazia(pLista2)) {
        pLista2->pUltimo->pProx = pLista1->pPrimeiro->pProx;
        pLista1->pPrimeiro->pProx = pLista2->pPrimeiro->pProx;
        pLista2->pPrimeiro->pProx = NULL;
        pLista2->pUltimo = pLista2->pPrimeiro;
    }
}

// Analisa a lista original e coloca os caracteres na lista resultado ou auxiliar
void resolve(Lista *original, Lista *resultado, Lista *auxiliar) {
    int flag = 0;
    Celula *pAux;
    Item temp;

    // Percorre a lista original, caractere por caractere
    pAux = original->pPrimeiro->pProx;
    while (pAux != NULL) {
        // Se o caractere for ']' então incluir os caracteres da lista auxiliar na lista resultado
        if (pAux->item.letra == ']' || pAux->item.letra == '[') {
            if (flag == 1) {
                // A flag deve indicar que "End" foi pressionado
                flag = 0;
                // Se a lista auxiliar não estiver vazia
                if (!ListaEhVazia(auxiliar)) {
                    // Incluir o conteúdo da lista auxiliar na lista de resultado
                    ListaInclude(resultado, auxiliar);
                    // Iniciar os ponteiros da lista auxiliar novamente
                    ListaInicia(auxiliar);
                }
            }
        }

        // Se ler o caractere '[', a flag deve indicar que "Home" foi pressionado
        if (pAux->item.letra == '[') {
            flag = 1;
        }

        // Se ler um caractere sem "Home" ter sido pressionado, inserir direto no final da lista de resultado
        if (pAux->item.letra != '[' && pAux->item.letra != ']' && flag == 0) {
            temp.letra = pAux->item.letra;
            ListaInsereFinal(resultado, temp);
        }
        // Se ler um caractere com "Home" tendo sido pressionado, inserir na lista auxiliar
        else if (pAux->item.letra != '[' && pAux->item.letra != ']' && flag == 1) {
            temp.letra = pAux->item.letra;
            ListaInsereFinal(auxiliar, temp);
        }
        // Vai para a próxima célula
        pAux = pAux->pProx;
    }

    // Processa os últimos caracteres mesmo que não haja "Home" ou "End" no final da entrada
    if (flag == 1) {
        // Se a lista auxiliar não estiver vazia
        if (!ListaEhVazia(auxiliar)) {
            // Incluir o conteúdo da lista auxiliar na lista de resultado
            ListaInclude(resultado, auxiliar);
        }
    }
}
