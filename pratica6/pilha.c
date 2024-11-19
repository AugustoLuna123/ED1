#include "pilha.h"

int PilhaInicia(Pilha* pPilha) {
    return ListaInicia(pPilha);
}

int PilhaEhVazia(Pilha* pPilha) {
    return ListaEhVazia(pPilha);
}

int PilhaPush(Pilha* pPilha, Item item) {
    return ListaInserePrimeiro(pPilha, item);
}

int PilhaPop(Pilha* pPilha, Item* pItem) {
    return ListaRetiraPrimeiro(pPilha, pItem);
}

void PilhaEsvazia(Pilha* pPilha) {
    ListaEsvazia(pPilha);
}
