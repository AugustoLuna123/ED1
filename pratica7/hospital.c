#include "hospital.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lePacientes(Paciente* pacientes, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", pacientes[i].nome, &pacientes[i].nascimento.dia,
                             &pacientes[i].nascimento.mes, &pacientes[i].nascimento.ano);
    }
}

void troca(Paciente* p1, Paciente* p2) {
    Paciente temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

bool ehMaisNovo(const Data* d1, const Data* d2) {
    if (d1->ano < d2->ano)
        return true;
    if (d1->ano > d2->ano)
        return false;
    if (d1->mes < d2->mes)
        return true;
    if (d1->mes > d2->mes)
        return false;
    if (d1->dia < d2->dia)
        return true;
    return false;
}

void bubblesort(Hospital* hospital, int* comp, int* mov) {
    *comp = 0;
    *mov = 0;
    for (int i = 0; i < hospital->n - 1; i++) {
        for (int j = 0; j < hospital->n - i - 1; j++) {
            (*comp)++;
            if (ehMaisNovo(&hospital->pacientes[j + 1].nascimento, &hospital->pacientes[j].nascimento)) {
                troca(&hospital->pacientes[j], &hospital->pacientes[j + 1]);
                (*mov)++;
            }
        }
        
    }
}

void selectionsort(Hospital* hospital, int* comp, int* mov) {
    *comp = 0;
    *mov = 0;
    for (int i = 0; i < hospital->n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < hospital->n; j++) {
            (*comp)++;
            if (ehMaisNovo(&hospital->pacientes[j].nascimento, &hospital->pacientes[minIndex].nascimento)) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            troca(&hospital->pacientes[i], &hospital->pacientes[minIndex]);
            (*mov)++;
        }
    }
}

void insertionsort(Hospital* hospital, int* comp, int* mov) {
    *comp = 0;
    *mov = 0;
    for (int i = 1; i < hospital->n; i++) {
        Paciente chave = hospital->pacientes[i];
        int j = i - 1;
        (*mov)++;
        // Incrementar a comparação antes do loop
        (*comp)++;
        while (j >= 0 && ehMaisNovo(&chave.nascimento, &hospital->pacientes[j].nascimento)) {
            hospital->pacientes[j + 1] = hospital->pacientes[j];
            j--;
            if (j >= 0) {
                     // Incrementar a comparação dentro do loop
            }  
            (*comp)++; 
            (*mov)++;
        }
        hospital->pacientes[j + 1] = chave;
        if (i != j + 1) {
        }
    }
}
