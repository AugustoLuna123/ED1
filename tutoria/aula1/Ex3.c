#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[100];
    float preco;
} Produto;

typedef struct {
    Produto *produtos;  
    int tamanho;        
    int capacidade;    
} Inventario;

void inicializarInventario(Inventario *inv, int capacidade) {
    inv->produtos = (Produto *) malloc(capacidade * sizeof(Produto));
    if (inv->produtos == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para o inventário.\n");
        exit(1);
    }
    inv->tamanho = 0;
    inv->capacidade = capacidade;
}

void adicionarProduto(Inventario *inv, Produto prod) {
    if (inv->tamanho < inv->capacidade) {
        inv->produtos[inv->tamanho] = prod;
        inv->tamanho++;
    } else {
        fprintf(stderr, "Erro: inventário está cheio, não é possível adicionar mais produtos.\n");
    }
}

void removerProduto(Inventario *inv, int codigo) {
    int i, encontrado = 0;
    for (i = 0; i < inv->tamanho; i++) {
        if (inv->produtos[i].codigo == codigo) {
            encontrado = 1;
            for (; i < inv->tamanho - 1; i++) {
                inv->produtos[i] = inv->produtos[i + 1];
            }
            inv->tamanho--;
            break;
        }
    }
    if (!encontrado) {
        fprintf(stderr, "Erro: produto com código %d não encontrado no inventário.\n", codigo);
    }
}

void listarProdutos(Inventario *inv) {
    printf("Lista de produtos no inventário:\n");
    for (int i = 0; i < inv->tamanho; i++) {
        printf("Código: %d, Nome: %s, Preço: %.2f\n", inv->produtos[i].codigo, inv->produtos[i].nome, inv->produtos[i].preco);
    }
}

void imprimirQuantidade(Inventario *inv) {
    printf("O inventário possui %d produtos.\n", inv->tamanho);
}

void procurarProduto(Inventario *inv, int codigo) {
    int i, encontrado = 0;
    for (i = 0; i < inv->tamanho; i++) {
        if (inv->produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código: %d, Nome: %s, Preço: %.2f\n", inv->produtos[i].codigo, inv->produtos[i].nome, inv->produtos[i].preco);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        fprintf(stderr, "Erro: produto com código %d não encontrado no inventário.\n", codigo);
    }
}

void liberarInventario(Inventario *inv) {
    free(inv->produtos);
    inv->produtos = NULL;
    inv->tamanho = 0;
    inv->capacidade = 0;
}

int main() {
    Inventario inv;
    inicializarInventario(&inv, 10);  

    Produto p1 = {1, "Produto A", 10.50};
    Produto p2 = {2, "Produto B", 20.75};

    adicionarProduto(&inv, p1);
    adicionarProduto(&inv, p2);

    listarProdutos(&inv);

    imprimirQuantidade(&inv);

    procurarProduto(&inv, 1);

    removerProduto(&inv, 2);

    listarProdutos(&inv);

    imprimirQuantidade(&inv);

    liberarInventario(&inv);

    return 0;
}
