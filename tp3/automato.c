#include <stdio.h>
#include <stdlib.h>
#include "automato.h"
#include "double_hash.h"

// Função para alocar e inicializar o autômato celular
AutomatoCelular* alocarReticulado(int D) {
    AutomatoCelular* automato = (AutomatoCelular*) malloc(sizeof(AutomatoCelular));  // Aloca memória para o autômato
    automato->D = D;  // Define a dimensão do reticulado
    automato->tamanho = D * D;  // Calcula o tamanho da tabela como D^2 (tabela quadrada)
    automato->colisoes = 0;  // Inicializa o contador de colisões
    automato->tabela = (int*) malloc(automato->tamanho * sizeof(int));  // Aloca a tabela hash
    for (int i = 0; i < automato->tamanho; i++) {
        automato->tabela[i] = -1;  // Inicializa todas as células da tabela com -1 (vazias)
    }
    return automato;  // Retorna o ponteiro do autômato
}

// Função para desalocar a memória do autômato celular
void desalocarReticulado(AutomatoCelular* automato) {
    free(automato->tabela);  // Libera a memória da tabela
    free(automato);  // Libera a memória do autômato
}

// Função para armazenar um valor em uma célula usando hash duplo
void armazenarValor(AutomatoCelular* automato, int chave, int valor) {
    int i = 0;  // Inicializa o índice de tentativas de hash duplo
    int posicao = hash_duplo(chave, i, automato->tamanho);  // Calcula a posição inicial usando hash duplo

    // Tenta inserir o valor enquanto houver colisão
    while (automato->tabela[posicao] != -1 && i < automato->tamanho) {
        automato->colisoes++;  // Incrementa o contador de colisões
        i++;  // Incrementa o número de tentativas
        posicao = hash_duplo(chave, i, automato->tamanho);  // Calcula nova posição
    }

    automato->tabela[posicao] = valor;  // Armazena o valor na posição calculada
}

// Função para obter o valor de uma célula usando hash duplo
int obterValor(AutomatoCelular* automato, int chave) {
    int i = 0;  // Inicializa o índice de tentativas
    int posicao = hash_duplo(chave, i, automato->tamanho);  // Calcula a posição inicial

    // Percorre a tabela até encontrar a chave ou chegar ao fim
    while (automato->tabela[posicao] == -1 && i < automato->tamanho) {
        i++;  // Incrementa o número de tentativas
        posicao = hash_duplo(chave, i, automato->tamanho);  // Calcula nova posição
    }

    return automato->tabela[posicao];  // Retorna o valor armazenado na posição
}

// Função para leitura do reticulado
void leituraReticulado(AutomatoCelular* automato) {
    for (int i = 0; i < automato->tamanho; i++) {
        int valor;
        scanf("%d", &valor);  // Lê um valor para cada célula
        armazenarValor(automato, i, valor);  // Armazena o valor usando a função de hash
    }
}

// Função para imprimir o reticulado
void imprimeReticulado(AutomatoCelular* automato) {
    for (int i = 0; i < automato->tamanho; i++) {
        int valor = obterValor(automato, i);  // Obtém o valor de cada célula
        printf("%d ", valor);  // Imprime o valor
        if ((i + 1) % automato->D == 0) {  // Insere uma nova linha após imprimir uma linha completa
            printf("\n");
        }
    }
}

// Função para evoluir o reticulado com base nas regras do jogo da vida
void evoluirReticulado(AutomatoCelular* automato, int geracoes) {
    int D = automato->D;  // Tamanho do grid
    int* novaGeracao = (int*) malloc(automato->tamanho * sizeof(int));  // Aloca memória para a nova geração

    for (int g = 0; g < geracoes; g++) {  // Loop pelas gerações
        for (int i = 0; i < D; i++) {  // Percorre as linhas do grid
            for (int j = 0; j < D; j++) {  // Percorre as colunas do grid
                int vivos = 0;  // Conta células vivas
                int posicaoAtual = i * D + j;  // Calcula a posição atual

                // Verifica as células vizinhas
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;  // Ignora a célula central
                        int vizinhoI = i + x;
                        int vizinhoJ = j + y;
                        if (vizinhoI >= 0 && vizinhoI < D && vizinhoJ >= 0 && vizinhoJ < D) {
                            int vizinhoPos = vizinhoI * D + vizinhoJ;
                            vivos += obterValor(automato, vizinhoPos);  // Soma o valor da célula vizinha
                        }
                    }
                }

                // Aplica as regras do jogo da vida
                if (obterValor(automato, posicaoAtual) == 1) {  // Célula viva
                    if (vivos < 2 || vivos > 3)
                        novaGeracao[posicaoAtual] = 0;  // Célula morre
                    else
                        novaGeracao[posicaoAtual] = 1;  // Célula continua viva
                } else {  // Célula morta
                    if (vivos == 3)
                        novaGeracao[posicaoAtual] = 1;  // Célula renasce
                    else
                        novaGeracao[posicaoAtual] = 0;  // Célula continua morta
                }
            }
        }

        // Atualiza a geração
        for (int i = 0; i < automato->tamanho; i++) {
            armazenarValor(automato, i, novaGeracao[i]);  // Atualiza o reticulado
        }
    }

    free(novaGeracao);  // Libera memória da nova geração
}
