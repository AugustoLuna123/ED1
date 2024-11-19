#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int main() {
    int dimensao, geracoes;
    scanf("%d", &dimensao); // le a dimensão da grade a partir da entrada padrão
    scanf("%d", &geracoes); // le o número de gerações a serem simuladas

    AutomatoCelular *automato = alocarReticulado(dimensao, geracoes); // aloca e inicializa o autômato celular

    leituraReticulado(automato); // le o estado inicial do reticulado

    int geracoesProcessadas = evoluirReticulado(automato, automato->geracoes); // evolui o reticulado pelo número especificado de gerações
    
    if (geracoesProcessadas < automato->geracoes) {
        printf("Erro ao evoluir o reticulado\n"); // imprime mensagem de erro se o número de gerações processadas for menor que o esperado
        desalocarReticulado(automato); // libera a memória alocada
        return 1; // termina o programa com erro
    }

    imprimeReticulado(automato); // imprime o estado final do reticulado

    desalocarReticulado(automato); // libera a memória alocada

    return 0;
}
