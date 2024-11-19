#include <stdio.h>
#include <stdlib.h>
#include "automato.h"


int main() {
    int dimensao, geracoes;
    scanf("%d", &dimensao);
    scanf("%d", &geracoes);

    AutomatoCelular *automato = alocarReticulado(dimensao, geracoes);

    leituraReticulado(automato);

    int geracoesProcessadas = evoluirReticulado(automato, automato->geracoes);
    if (geracoesProcessadas < automato->geracoes) {
        printf("Erro ao evoluir o reticulado\n");
        desalocarReticulado(automato);
        return 1;
        
    } else

    imprimeReticulado(automato);

    desalocarReticulado(automato);

    return 0;
}
