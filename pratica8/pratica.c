#include "ordenacao.h"
#include <stdio.h>

int main() {
    int n, k;
    Aluno* alunos;

    // Ler quantidade de alunos e k
    leQuantidades(&n, &k);

    // Alocar vetor dinâmico de alunos
    alunos = alocaAlunos(n);

    // Ler nomes dos alunos
    leAlunos(alunos, n);

    // Ordenar os alunos pelo nome usando Shell Sort
    ordena(alunos, n);

    // Imprimir o nome do aluno que deve receber o bônus
    imprimeResposta(alunos, n, k);

    // Liberar vetor de alunos
    liberaAlunos(&alunos);

    return 0;
}
