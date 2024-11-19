#include <stdio.h>
#include <string.h>
#include "aula1Ex3.h"

typedef struct {
    int codigo;
    char nome[100];
    float preço;
} Produto;

typedef struct {
    int qtdProdutos;
    Produto* produtos;
} Inventario;

Produto* inicializaInvetario(int qtdProdutos){
    Produto* produto = (Produto*)malloc(sizeof(Produto)* qtdProdutos);

    for (int i = 0; i < qtdProdutos; i++) {
        produto[i].codigo = 0;
        strcpy(produto[i].nome, "Sem nome!");
        produto[i].preço = 0;
    }

    return produto;
}

void adicionaProduto (Produto produto){
    printf("Digite o codigo do produto: \n");
    scanf("%d", &produto.codigo);
    printf("Digite o nome do produto: \n");
    scanf("%c", &produto.nome);
    printf("Digite o preço do produto: \n");
    scanf("%f", &produto.preço);
}

void removeProduto(Produto produto);



