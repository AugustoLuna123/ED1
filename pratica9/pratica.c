#include <stdio.h>

#include "hash.h"

int main() {
    Hash hash;
    Chave chave;
    int n;

      int m, p, s;

    // Ler a quantidade de casos
    scanf("%d", &n);

    while (n-- > 0) {
    
        
        // Lendo tamanho da tabela e quantidade de pesos
        scanf("%d %d", &m, &p);

        // Iniciar Hash
        inicia(&hash, m, p);

        // Lendo pesos
        for (int i = 0; i < p; i++) {
            scanf("%d", &hash.pesos[i]);
        }

        // Lendo quantidade de chaves
        scanf("%d", &s);

        int posicao = -1;
        for (int i = 0; i < s; i++) {
            scanf("%s", chave);
            posicao = insere(&hash, chave);
        }

        // Imprimir resposta
        printf("%d\n", posicao);

        // Liberar Hash
        libera(&hash);
    }

    return 0;
}
