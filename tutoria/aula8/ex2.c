#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top1; 
    int top2; 
} Pilhas;


void initTwoStacks(Pilhas *pilha) {
    pilha->top1 = -1;
    pilha->top2 = MAX_SIZE; 
}


void push1(Pilhas *pilha, int item) {
    if (pilha->top1 < pilha->top2 - 1) { 
        pilha->data[++pilha->top1] = item;
    } else {
        printf("Estouro de pilha 1.\n");
    }
}

void push2(Pilhas *pilha, int item) {
    if (pilha->top2 > pilha->top1 + 1) {
        pilha->data[--pilha->top2] = item;
    } else {
        printf("Estouro de pilha 2.\n");
    }
}

int pop1(Pilhas *pilha) {
    if (pilha->top1 >= 0) {
        return pilha->data[pilha->top1--];
    } else {
        printf("Pilha 1 vazia.\n");
        return -1;
    }
}

int pop2(Pilhas *pilha) {
    if (pilha->top2 < MAX_SIZE) {
        return pilha->data[pilha->top2++];
    } else {
        printf("Pilha 2 vazia.\n");
        return -1; 
    }
}

int main() {
    Pilhas pilha;
    initTwoStacks(&pilha);

    push1(&pilha, 1);
    push1(&pilha, 2);
    push1(&pilha, 3);

    push2(&pilha, 4);
    push2(&pilha, 5);

    printf("Elemento desempilhado da pilha 1: %d\n", pop1(&pilha));
    printf("Elemento desempilhado da pilha 2: %d\n", pop2(&pilha));

    return 0;
}
