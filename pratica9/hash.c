#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Manter como especificado
void inicia(Hash *hash, int m, int p) {
    hash->m = m;
    hash->p = p;
    hash->chaves = (Chave*) malloc(m * sizeof(Chave));
    hash->pesos = (int*) malloc(p * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        hash->chaves[i][0] = '\0';
    }
}

// Manter como especificado
void libera(Hash *hash) {
    free(hash->chaves);
    free(hash->pesos);
}

// Função de transformação H(s)
int H(Hash* hash, Chave chave) {
    unsigned long long hashValue = 0;
    int len = strlen(chave);
    
    for (int i = 0, j = 0; i < len; i++) {
        char c = chave[i];
        // Ignora caracteres não alfabéticos
        if (isalpha(c)) {
            // Torna o caractere case insensitive
            c = tolower(c);
            hashValue += (c * hash->pesos[j % hash->p]);
            j++;
        }
    }
    
    return hashValue % hash->m;
}

// Manter como especificado
int insere(Hash *hash, Chave chave) {
    int posicao = H(hash, chave);
    int originalPos = posicao;
    int i = 0;
    
    while (hash->chaves[posicao][0] != '\0') {
        if (strcmp(hash->chaves[posicao], chave) == 0) {
            return -1; // Chave duplicada
        }
        
        i++;
        posicao = (originalPos + i) % hash->m;
    }
    
    strcpy(hash->chaves[posicao], chave);
    return posicao;
}
