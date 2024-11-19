#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int x;
    int y;

} Ponto;

typedef struct{

    Ponto pontoInferiorEsquerdo;
    Ponto pontoSuperiorDireito;

} Retangulo;

Ponto* criaPonto(int x, int y){

    Ponto* ponto = (Ponto*)malloc(sizeof(Ponto));


    if(ponto == NULL){
        printf("Memoria insuficiente: ");
        exit(1);
    }

    ponto->x = x;
    ponto->y = y;

    return ponto;
}

/*void apagaPonto (Ponto** ponto){

}*/

Ponto** criarVetorPontos(int n){
    Ponto** vetor = (Ponto**)malloc(n * sizeof(Ponto*));

         if(vetor == NULL){
        printf("Memoria insuficiente: ");
        exit(1);
    }

    return *vetor;

}

void apagaVetorPontos(Ponto** vetor, int n ){
    for(int i = 0; i<n; i++){
        free(*vetor);
    }
}

void inicializaVetorPontos(Ponto** vetor, int n){
    for(int i = 0; i<n; i++){
        scanf("%d", &vetor[i]->x);
        scanf("%d", &vetor[i]->y);
    }
}

void imprimirVetorPontos(Ponto** vetor, int n){
    for(int i = 0; i<n; i++){
        printf("Valor de X do ponto %d: %d \n", i, vetor[i]->x);
        printf("Valor de Y do ponto %d: %d \n", i, vetor[i]->y);
    }
    printf("\n");
}

Retangulo* criaRetangulo(Ponto* p1, Ponto* p2){
    Retangulo* retangulo = (Retangulo*)malloc(sizeof(Retangulo));

    retangulo->pontoInferiorEsquerdo.x = p1->x;
    retangulo->pontoInferiorEsquerdo.y = p1->y;
    retangulo->pontoSuperiorDireito.x = p2->x;
    retangulo->pontoSuperiorDireito.y = p2->y;

    return retangulo;
    
}

void apagaRetangulo (Retangulo** retangulo){

}

void imprimirRetangulo(Retangulo* retangulo){
    prinf("Ponto 1: %d \n", retangulo->pontoInferiorEsquerdo);
    printf("Ponto 2: %d \n", retangulo->pontoSuperiorDireito);
}

bool pontoDentroRetangulo(Retangulo* retangulo, Ponto* ponto){

    if(retangulo->pontoInferiorEsquerdo.x < ponto->x && retangulo->pontoInferiorEsquerdo.y < ponto->y || retangulo->pontoSuperiorDireito.x > ponto->x && retangulo->pontoSuperiorDireito.y > ponto->y){
        return true;
    } else return false;
}

void verificaPontosDentroRet(Retangulo* retangulo, Ponto** vetor, int n){
    
}