#include <stdio.h>
#include <stdlib.h>
#include "automato.h"
#include "matriz.h"

AutomatoCelular* alocarReticulado(int dimensao, int geracoes) {
    AutomatoCelular *automato = (AutomatoCelular *)malloc(sizeof(AutomatoCelular)); 
    automato->dimensao = dimensao; // define a dimensão da grade
    automato->geracoes = geracoes; // define o número de gerações
    automato->grade = criarMatrizEsparsa(dimensao); // cria a matriz esparsa que representa o reticulado
    return automato; 
}

// função que libera a memória alocada para o autômato celular
void desalocarReticulado(AutomatoCelular *automato) {
    liberarMatrizEsparsa(automato->grade);
    free(automato); 
}

// função que lê o estado inicial do reticulado a partir da entrada
void leituraReticulado(AutomatoCelular *automato) {
    for (int i = 0; i < automato->dimensao; i++) { 
        for (int j = 0; j < automato->dimensao; j++) {
            int valor;
            scanf("%d", &valor); 
            if (valor != 0) {
                inserirElemento(automato->grade, i, j, valor); // insere o valor na matriz esparsa se for diferente de zero
            }
        }
    }
}

// função que imprime o estado atual do reticulado
void imprimeReticulado(AutomatoCelular *automato) {
    imprimirMatrizEsparsa(automato->grade); // Imprime a matriz esparsa no formato bidimensional
}

// função que calcula a próxima geração do autômato celular
void calcularProximaGeracao(AutomatoCelular *automato, MatrizEsparsa *novaGrade) {
    for (int i = 0; i < automato->dimensao; i++) { 
        for (int j = 0; j < automato->dimensao; j++) {
            int vivos = 0; // contador de células vivas ao redor da célula atual
            for (int linhasVizinhas = -1; linhasVizinhas <= 1; linhasVizinhas++) {
                for (int colunasVizinhas = -1; colunasVizinhas <= 1; colunasVizinhas++) {
                    if (linhasVizinhas == 0 && colunasVizinhas == 0) continue; // ignora a célula atual
                    int ni = i + linhasVizinhas; // indice da linha vizinha
                    int nj = j + colunasVizinhas; // indice da coluna vizinha
                    if (ni >= 0 && ni < automato->dimensao && nj >= 0 && nj < automato->dimensao) {
                        vivos += obterElemento(automato->grade, ni, nj); // conta as celulas vivas ao redor
                    }
                }
            }

            int valorAtual = obterElemento(automato->grade, i, j); // obtém o valor atual da célula na posição (i, j)
            if (valorAtual == 1) { // se a célula está viva
                if (vivos < 2 || vivos > 3) { // morre por solidão ou superpopulação
                    inserirElemento(novaGrade, i, j, 0); // define como morta na nova geração
                } else {
                    inserirElemento(novaGrade, i, j, 1); // sobrevive
                }
            } else {
                if (vivos == 3) { // torna-se viva
                    inserirElemento(novaGrade, i, j, 1); // insere a célula viva na nova geração
                } else {
                    inserirElemento(novaGrade, i, j, 0); // permanece morta
                }
            }
        }
    }
}

// função que evolui o reticulado por um determinado número de gerações
int evoluirReticulado(AutomatoCelular *automato, int geracoesRestantes) {
    if (geracoesRestantes == 0) {
        return 0; 
    }

    MatrizEsparsa *novaGrade = criarMatrizEsparsa(automato->dimensao); // cria a matriz esparsa para a nova geração

    calcularProximaGeracao(automato, novaGrade); // calcula a próxima geração

    liberarMatrizEsparsa(automato->grade); // libera a matriz da geração anterior
    automato->grade = novaGrade; // atualiza o reticulado com a nova geração

    return evoluirReticulado(automato, geracoesRestantes - 1) + 1; // chama recursivamente para evoluir as gerações restantes
}
