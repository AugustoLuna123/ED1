#include <stdio.h>
#include "automato.h"

int main() {
    int D, geracoes;

    // Lê a dimensão do reticulado e o número de gerações
    scanf("%d %d", &D, &geracoes);

    // Aloca o reticulado
    AutomatoCelular* automato = alocarReticulado(D);

    // Leitura do estado inicial do reticulado
    leituraReticulado(automato);

    // Evolução do reticulado
    evoluirReticulado(automato, geracoes);

    // Impressão do reticulado após as gerações
    imprimeReticulado(automato);

    //printf("Número de colisões: %d\n", automato->colisoes);

    // Desaloca o reticulado
    desalocarReticulado(automato);

    return 0;
}
