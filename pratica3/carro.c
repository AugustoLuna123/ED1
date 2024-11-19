#include "carro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct funcionario {
    char nome[21];
    int mat;
};


struct carro {
    int chassi;
    char marca [21];
    int lugares;
    int ano;
    Funcionario* func;
};

Funcionario* FuncionarioAloca() {
    Funcionario* funcionario = (Funcionario*)malloc(sizeof(Funcionario));

    if( funcionario == NULL){
        printf("Memoria insuficiente: \n");
        exit(1);
    }

    return funcionario;
}

void FuncionarioDesaloca(Funcionario** func) {
    free(*func);
}

Carro* CarroAloca(int n) {
    Carro* carros = (Carro*)malloc(n * sizeof(Carro));

    if(carros == NULL){
        printf("Memoria insuficiente: \n");
        exit(1);
    }
        for(int i = 0; i<n; i++){
            carros[i].func = FuncionarioAloca();
        }

        return carros;
}

void CarroDesaloca(Carro** carros, int n) {
    for(int i = 0; i<n; i++){
        FuncionarioDesaloca(&(*carros)[i].func);
    }
        free(*carros);
}  


void le(Carro* carros, int n) {
    for(int i = 0; i< n; i++){
        scanf("%d", &carros[i].chassi);
        scanf("%s", carros[i].marca);
        scanf("%d", &carros[i].lugares);
        scanf("%d", &carros[i].ano);
        scanf("%s", carros[i].func->nome);
        scanf("%d", &carros[i].func->mat);
    }
}

int conta(Carro* carros, int n, const int ano, const int lugares) {

    if (n == 0){
        return 0;
    }

    if(carros[n -1 ].ano > ano && carros[n-1].lugares > lugares){
        
        return 1 + conta(carros, n - 1, ano, lugares);
    }

    else 

        return conta(carros, n-1, ano, lugares);
}

void imprime(Carro* carros, int n, const char* nome) {

    if(n == 0){
        return;
    }
        if(strcmp(carros[n - 1].func->nome, nome) == 0){
            printf("%s [%d |%d |%d]", carros[n - 1].marca, carros[n - 1].ano, carros[n - 1].lugares, carros[n - 1].chassi);
        } 
        imprime(carros, n - 1, nome);

}
