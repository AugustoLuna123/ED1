#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_HEAP_SIZE 100

// Protótipo da função temMaisPrioridade para evitar declaração implícita
bool temMaisPrioridade(Chamada* c1, Chamada* c2);

// Refaz o heap da raiz para as folhas
void refaz(Heap *heap, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < heap->tam && temMaisPrioridade(&heap->chamadas[esq], &heap->chamadas[maior])) {
        maior = esq;
    }

    if (dir < heap->tam && temMaisPrioridade(&heap->chamadas[dir], &heap->chamadas[maior])) {
        maior = dir;
    }

    if (maior != i) {
        Chamada temp = heap->chamadas[i];
        heap->chamadas[i] = heap->chamadas[maior];
        heap->chamadas[maior] = temp;
        refaz(heap, maior);
    }
}

// Insere uma chamada na posição index
void heapInsere(Heap *heap, Chamada chamada, int index) {
    int i = index;
    heap->chamadas[i] = chamada;

    // Ajusta a posição para manter a propriedade do heap
    while (i > 0 && temMaisPrioridade(&heap->chamadas[i], &heap->chamadas[(i - 1) / 2])) {
        Chamada temp = heap->chamadas[i];
        heap->chamadas[i] = heap->chamadas[(i - 1) / 2];
        heap->chamadas[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Retorna true se c1 tem mais prioridade do que c2.
// Se forem iguais, retorna true se c1 for mais velho.
bool temMaisPrioridade(Chamada* c1, Chamada* c2) {
    // Comparando pela prioridade
    if (c1->prioridade > c2->prioridade) {
        return true;
    } else if (c1->prioridade < c2->prioridade) {
        return false;
    }
    
    // Se as prioridades forem iguais, comparar pela idade (mais velho tem prioridade)
    if (c1->nascimento.ano < c2->nascimento.ano) {
        return true;
    } else if (c1->nascimento.ano > c2->nascimento.ano) {
        return false;
    }
    
    if (c1->nascimento.mes < c2->nascimento.mes) {
        return true;
    } else if (c1->nascimento.mes > c2->nascimento.mes) {
        return false;
    }
    
    if (c1->nascimento.dia < c2->nascimento.dia) {
        return true;
    } else {
        return false;
    }
}


// Cria e retorna um tipo chamada baseado nas informações fornecidas
Chamada criarChamada(char *nome, int prioridade, int dia, int mes, int ano) {
    Chamada chamada;
    strcpy(chamada.nome, nome);
    chamada.prioridade = prioridade;
    chamada.nascimento.dia = dia;
    chamada.nascimento.mes = mes;
    chamada.nascimento.ano = ano;
    return chamada;
}

// Cria e retorna um heap vazio
Heap* criarHeap() {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->tam = 0;
    return heap;
}

// Destroi o heap alocado
Heap* destroiHeap(Heap *heap) {
    free(heap);
    return NULL;
}

// Insere uma chamada no heap
void inserirChamada(Heap *heap, Chamada chamada) {
    if (heap->tam >= MAX_HEAP_SIZE) {
        printf("Erro: Heap cheio!\n");
        return;
    }
    heapInsere(heap, chamada, heap->tam);
    heap->tam++;
}

// Remove a chamada com mais prioridade do heap
Chamada atenderChamada(Heap *heap) {
    if (heap->tam == 0) {
        printf("Erro: Heap vazio!\n");
        exit(1);
    }

    Chamada chamadaAtendida = heap->chamadas[0];
    heap->chamadas[0] = heap->chamadas[heap->tam - 1];
    heap->tam--;
    refaz(heap, 0);

    return chamadaAtendida;
}

// Verifica se ainda tem chamadas no heap
bool consultarSeTemProximaChamada(Heap *heap) {
    return heap->tam > 0;
}

void imprimeChamada(Chamada chamada) {
    printf("%02d | %02d/%02d/%04d | %s\n", 
           chamada.prioridade, 
           chamada.nascimento.dia, 
           chamada.nascimento.mes, 
           chamada.nascimento.ano, 
           chamada.nome);
}

