#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

struct duende {
    char nome[21];
    int idade;
    ESCALADO escalado;
};

struct time {
    char nomeLider[21];
    int idadeLider;
    char nomeConfeiteiro[21];
    int idadeConfeiteiro;
    char nomeEntregador[21];
    int idadeEntregador;
    char nomeEmbrulhador[21];
    int idadeEmbrulhador;
};

// Manter como especificado
void lerQuantidade(int *qtdDuendes) {
    scanf("%d", qtdDuendes);
}

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes) {
    return (Duende*) malloc(qtdDuendes * sizeof(Duende));
}

// Manter como especificado
Time *alocaTimes(int qtdTimes) {
    return (Time*) malloc(qtdTimes * sizeof(Time));
}

// Manter como especificado
void desalocaDuendes(Duende **duendes) {
    free(*duendes);
    *duendes = NULL;
}

// Manter como especificado
void desalocaTimes(Time **times) {
    free(*times);
    *times = NULL;
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes) {
    for (int i = 0; i < qtdDuendes; i++) {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
        duendes[i].escalado = NAO;
    }
}

// Função para encontrar o próximo duende mais velho disponível
int proximoMaisVelho(Duende *duendes, int qtdDuendes) {
    int index = -1;
    for (int i = 0; i < qtdDuendes; i++) {
        if (duendes[i].escalado == NAO) {
            if (index == -1 || duendes[i].idade > duendes[index].idade) {
                index = i;
            }
        }
    }
    return index;
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes) {
    int qtdTimes = qtdDuendes / 4;
    int i, index;

    // Escalando os líderes
    for (i = 0; i < qtdTimes; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeLider, duendes[index].nome);
        times[i].idadeLider = duendes[index].idade;
    }

    // Escalando os confeiteiros
    for (i = 0; i < qtdTimes; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeConfeiteiro, duendes[index].nome);
        times[i].idadeConfeiteiro = duendes[index].idade;
    }

    // Escalando os entregadores
    for (i = 0; i < qtdTimes; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeEntregador, duendes[index].nome);
        times[i].idadeEntregador = duendes[index].idade;
    }

    // Escalando os embrulhadores
    for (i = 0; i < qtdTimes; i++) {
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendes[index].escalado = SIM;
        strcpy(times[i].nomeEmbrulhador, duendes[index].nome);
        times[i].idadeEmbrulhador = duendes[index].idade;
    }
}

// Manter como especificado
void printTimes(Time *times, int qtdTimes) {
    for (int i = 0; i < qtdTimes; i++) {
        printf("Time %d\n", i + 1);
        printf("PILOTO > %s %d\n", times[i].nomeLider, times[i].idadeLider);
        printf("CONFEI > %s %d\n", times[i].nomeConfeiteiro, times[i].idadeConfeiteiro);
        printf("ENTREG > %s %d\n", times[i].nomeEntregador, times[i].idadeEntregador);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrulhador, times[i].idadeEmbrulhador);
    }
}
