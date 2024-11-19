#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de ordenação usando Shell Sort
void ordena(Aluno *alunos, int n) {
    int i, j, h;
    Aluno aux;
    
    for (h = 1; h < n / 3; h = 3 * h + 1);
    
    for (; h > 0; h /= 3) {
        for (i = h; i < n; i++) {
            aux = alunos[i];
            j = i;
            while (j >= h && compare(alunos[j - h].nome, aux.nome) > 0) {
                alunos[j] = alunos[j - h];
                j -= h;
            }
            alunos[j] = aux;
        }
    }
}

// Função de comparação de strings
int compare(const char* aluno1, const char* aluno2) {
    return strcmp(aluno1, aluno2);
}

// Função para imprimir o nome do aluno premiado
void imprimeResposta(Aluno* alunos, int n, int k) {
    printf("%s\n", alunos[n - k].nome);
}

// Função para alocar vetor dinâmico de alunos
Aluno* alocaAlunos(int n) {
    return (Aluno*) malloc(n * sizeof(Aluno));
}

// Função para liberar vetor dinâmico de alunos
void liberaAlunos(Aluno** alunos) {
    free(*alunos);
    *alunos = NULL;
}

// Função para ler nomes dos alunos
void leAlunos(Aluno* alunos, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", alunos[i].nome);
    }
}

// Função para ler quantidade de alunos e o valor de k
void leQuantidades(int* n, int* k) {
    scanf("%d %d", n, k);
}
