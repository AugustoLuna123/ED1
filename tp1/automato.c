#include <stdio.h>      
#include <stdlib.h>     
#include "automato.h"   

AutomatoCelular* alocarReticulado(int dimensao, int geracoes) {
    AutomatoCelular *automato = (AutomatoCelular *)malloc(sizeof(AutomatoCelular)); 
    if (automato == NULL) return NULL; 

    automato->dimensao = dimensao; // Define a dimensão da grade
    automato->geracoes = geracoes; // Define o número de gerações
    automato->grade = (int **)malloc(dimensao * sizeof(int *)); // Aloca memória para a matriz de ponteiros
    if (automato->grade == NULL) {
         printf("Não há memória suficiente");
         exit(1);
    }

    for (int i = 0; i < dimensao; i++) {
        automato->grade[i] = (int *)malloc(dimensao * sizeof(int)); // Aloca memória para cada linha da matriz
        if (automato->grade[i] == NULL) { 
            printf("Não há memória suficiente");
            exit(1);
        }
    }

    return automato; // Retorna o ponteiro para a estrutura alocada
}

void desalocarReticulado(AutomatoCelular *automato) {
    for (int i = 0; i < automato->dimensao; i++) {
        free(automato->grade[i]); // Libera a memória alocada para cada linha da matriz
    }
    free(automato->grade); // Libera a memória alocada para a matriz de ponteiros
    free(automato); // Libera a memória alocada para a estrutura AutomatoCelular
}

void leituraReticulado(AutomatoCelular *automato) {
    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            scanf("%d", &automato->grade[i][j]); // Lê os valores da grade a partir da entrada padrão
        }
    }
}

void imprimeReticulado(AutomatoCelular *automato) {
    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            printf("%d ", automato->grade[i][j]); // Imprime os valores da grade
        }
        printf("\n"); // Nova linha após cada linha da grade
    }
}

void calcularProximaGeracao(AutomatoCelular *automato, int **novaGrade) {
    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            int vivos = 0; // Contador de células vivas ao redor da célula atual
            for (int linhasVizinhas = -1;  linhasVizinhas <= 1; linhasVizinhas++) {
                for (int colunasVizinhas = -1; colunasVizinhas <= 1; colunasVizinhas++) {
                    if (linhasVizinhas == 0 && colunasVizinhas == 0) continue; // Ignora a célula atual
                    int ni = i + linhasVizinhas; // Índice da linha vizinha
                    int nj = j + colunasVizinhas; // Índice da coluna vizinha
                    if (ni >= 0 && ni < automato->dimensao && nj >= 0 && nj < automato->dimensao) { // Verifica se o vizinho está dentro dos limites da grade
                        vivos += automato->grade[ni][nj]; // Incrementa o contador de células vivas
                    }
                }
            }

            if (automato->grade[i][j] == 1) {
                if (vivos < 2 || vivos > 3) { // Morre por solidão ou superpopulação
                    novaGrade[i][j] = 0;
                } else {
                    novaGrade[i][j] = 1; // Sobrevive
                }
            } else {
                if (vivos == 3) { // Torna-se viva
                    novaGrade[i][j] = 1;
                } else {
                    novaGrade[i][j] = 0;
                }
            }
        }
    }
}

int evoluirReticulado(AutomatoCelular *automato, int geracoesRestantes) {
    if (geracoesRestantes == 0){ // Termina a recursão quando não há mais gerações restantes
        return 0;
    }  

    int **novaGrade = (int **)malloc(automato->dimensao * sizeof(int *)); // Aloca memória para a nova geração
    for (int i = 0; i < automato->dimensao; i++) {
        novaGrade[i] = (int *)malloc(automato->dimensao * sizeof(int)); // Aloca memória para cada linha da nova geração
    }

    calcularProximaGeracao(automato, novaGrade); // Calcula a próxima geração

    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            automato->grade[i][j] = novaGrade[i][j]; // Atualiza a grade com a nova geração
        }
    }

    for (int i = 0; i < automato->dimensao; i++) {
        free(novaGrade[i]); // Libera a memória da nova geração
    }
    free(novaGrade); // Libera a memória da matriz de ponteiros da nova geração

    return evoluirReticulado(automato, geracoesRestantes - 1) + 1; // Chama recursivamente para evoluir as gerações restantes
}