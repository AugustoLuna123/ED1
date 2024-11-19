#include "double_hash.h"

int hash1(int chave, int tamanho) {
    // Aplicando o vetor de peso [1, 2] na primeira função hash
    int peso[] = {1, 2};
    return (peso[0] * chave + peso[1]) % tamanho;  // ajusta a função hash com pesos
}

int hash2(int chave, int tamanho) {
    // Aplicando o vetor de peso [3, 4] na segunda função hash
    int peso[] = {3, 4};
    return (peso[0] * chave + peso[1]) % tamanho;  // ajusta a função hash com pesos
}

int hash_duplo(int chave, int i, int tamanho) {
    // Função de hash duplo com hash1 e hash2
    return (hash1(chave, tamanho) + i * hash2(chave, tamanho)) % tamanho;
}
