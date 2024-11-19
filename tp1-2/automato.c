#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

AutomatoCelular* alocarReticulado(int dimensao, int geracoes) { // alocar memoria
    AutomatoCelular *automato = (AutomatoCelular *)malloc(sizeof(AutomatoCelular));
    if (automato == NULL) return NULL;

    automato->dimensao = dimensao;
    automato->geracoes = geracoes;
    automato->grade = (int **)malloc(dimensao * sizeof(int *));
    if (automato->grade == NULL) {
        free(automato);
        return NULL;
    }

    for (int i = 0; i < dimensao; i++) {
        automato->grade[i] = (int *)malloc(dimensao * sizeof(int));
        if (automato->grade[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(automato->grade[j]);
            }
            free(automato->grade);
            free(automato);
            return NULL;
        }
    }

    return automato;
}

void desalocarReticulado(AutomatoCelular *automato) {// liberar memoria
    for (int i = 0; i < automato->dimensao; i++) {
        free(automato->grade[i]);
    }
    free(automato->grade);
    free(automato);
}

void leituraReticulado(AutomatoCelular *automato) { //ler a dimensao e a matriz
    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            scanf("%d", &automato->grade[i][j]);
        }
    }
}

void imprimeReticulado(AutomatoCelular *automato) { //imprimir a grade
    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            printf("%d ", automato->grade[i][j]);
        }
        printf("\n");
    }
}

void calcularProximaGeracao(AutomatoCelular *automato, int **novaGrade) {
    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            int vivos = 0; // contador de celulas vivas
            for (int linhasVizinhas = -1;  linhasVizinhas <= 1; linhasVizinhas++) {
                for (int colunasVizinhas = -1; colunasVizinhas <= 1; colunasVizinhas++) {
                    if (linhasVizinhas == 0 && colunasVizinhas == 0) continue;
                    int ni = i + linhasVizinhas; // calculando o indice da linha vizinha
                    int nj = j + colunasVizinhas; // =^ coluna vizinha
                    if (ni >= 0 && ni < automato->dimensao && nj >= 0 && nj < automato->dimensao) { // verificar se está dentro dos limites da grade (matriz)
                        vivos += automato->grade[ni][nj];
                    }
                }
            }

            if (automato->grade[i][j] == 1) {
                if (vivos < 2 || vivos > 3) { // morre por solidão ou superpopulação
                    novaGrade[i][j] = 0;
                } else {
                    novaGrade[i][j] = 1;
                }
            } else {
                if (vivos == 3) { // se torna viva
                    novaGrade[i][j] = 1;
                } else {
                    novaGrade[i][j] = 0;
                }
            }
        }
    }
}

int evoluirReticulado(AutomatoCelular *automato, int geracoesRestantes) {
    if (geracoesRestantes == 0) return 0;

    int **novaGrade = (int **)malloc(automato->dimensao * sizeof(int *)); //cria uma nova grade para receber a geração

    for (int i = 0; i < automato->dimensao; i++) {
        novaGrade[i] = (int *)malloc(automato->dimensao * sizeof(int));
    
    }

    calcularProximaGeracao(automato, novaGrade);

    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            automato->grade[i][j] = novaGrade[i][j];
        }
    }

    for (int i = 0; i < automato->dimensao; i++) { //liberar a memoria da nova grade
        free(novaGrade[i]);
    }
    free(novaGrade);

    return evoluirReticulado(automato, geracoesRestantes - 1) + 1;
}
            