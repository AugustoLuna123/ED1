#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "lista.h"

bool pilhaPush(Pilha* pPilha, Item item){
    listaInsereInicio(pPilha, item);
}

bool pilhaPop(Pilha* pPilha, Item* pItem){
    listaRemoveInicio(pPilha, pItem);
}
