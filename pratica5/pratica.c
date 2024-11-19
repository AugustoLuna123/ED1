#include "lista.h"
#include <stdio.h>

int main() {
    Lista original, resultado, auxiliar;
    char letra;
    Item temp;

    //inicialize as três listas
    ListaInicia(&original);
    ListaInicia(&resultado);
    ListaInicia(&auxiliar);

    // le a linha da entrada
    while (scanf("%c", &letra) != EOF) {
        temp.letra = letra;
        // Insira o elemento temp na lista original
        ListaInsereFinal(&original, temp);
    }

    //analisa a lista original e coloca os caracteres na lista resultado ou auxiliar
    resolve(&original, &resultado, &auxiliar);

    //imprime o resultado, caso a lista não esteja vazia
    if (ListaEhVazia(&resultado))
        printf("Lista esta vazia: \n");
    else
    {
        ListaImprime(&resultado);
        printf("\n");
    }

    //ao final, desalocar as listas
    ListaEsvazia(&original);
    ListaEsvazia(&resultado);
    ListaEsvazia(&auxiliar);

    return 0; // Não remova
}
