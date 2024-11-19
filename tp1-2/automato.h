#ifndef AUTOMATO_H
#define AUTOMATO_H

typedef struct {
    int **grade;
    int dimensao;
    int geracoes;
} AutomatoCelular;

AutomatoCelular* alocarReticulado(int dimensao, int geracoes);
void desalocarReticulado(AutomatoCelular *automato);
void leituraReticulado(AutomatoCelular *automato);
void imprimeReticulado(AutomatoCelular *automato);
void calcularProximaGeracao(AutomatoCelular *automato, int **novaGrade);
int evoluirReticulado(AutomatoCelular *automato, int geracoesRestantes);

#endif
