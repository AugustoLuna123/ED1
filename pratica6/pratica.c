#include "pilha.h"
#include <stdio.h>

int main() {
    char ch;
    Item item;
    Pilha pilha;

    PilhaInicia(&pilha);

    
    while (scanf("%c", &ch) != EOF) {
        if (ch == '\n')
            break;
        
        if (ch == '(' || ch == ')') {
            if (ch == '(')
                PilhaPush(&pilha, ch);
            else {
                if (!PilhaEhVazia(&pilha))
                    PilhaPop(&pilha, &item);
                else {
                    PilhaPush(&pilha, ch);  
                    break;  
                }
            }
        }
    }

    if (PilhaEhVazia(&pilha))
        printf("correto\n");
    else
        printf("incorreto\n");

    PilhaEsvazia(&pilha);

    return 0;
}
