#ifndef pilha_h
#define pilha_h

#include "lista.h"

typedef Lista Pilha;

int PilhaInicia(Pilha* pPilha);
int PilhaEhVazia(Pilha* pPilha);
int PilhaPush(Pilha* pPilha, Item item);
int PilhaPop(Pilha* pPilha, Item* pItem);
void PilhaEsvazia(Pilha* pPilha);

#endif
