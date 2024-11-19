#ifndef AUTOMATO_H
#define AUTOMATO_H

typedef struct {
    int *tabela;  // tabela hash para armazenar o estado das células
    int tamanho;  // tamanho da tabela hash
    int D;        // dimensão do reticulado
    int colisoes; // contador de colisões
} AutomatoCelular;

AutomatoCelular* alocarReticulado(int D);
void desalocarReticulado(AutomatoCelular* automato);
void leituraReticulado(AutomatoCelular* automato);
void evoluirReticulado(AutomatoCelular* automato, int geracoes);
void imprimeReticulado(AutomatoCelular* automato);

#endif
