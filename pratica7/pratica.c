#include <stdio.h>
#include "hospital.h"
#include <string.h>

int main() {
    Hospital hospital, aux;
    int comp, mov;

    // Ler a quantidade de pacientes no hospital
    scanf("%d", &hospital.n);

    // Ler as informações dos pacientes
    lePacientes(hospital.pacientes, hospital.n);

    printf("Analise.....: Comp | Movi\n");

    // Bubble Sort
    memcpy(&aux, &hospital, sizeof(Hospital));
    bubblesort(&aux, &comp, &mov);
    printf("- Bubble....: %04d | %04d\n", comp, mov);

    // Selection Sort
    memcpy(&aux, &hospital, sizeof(Hospital));
    selectionsort(&aux, &comp, &mov);
    printf("- Selection.: %04d | %04d\n", comp, mov);

    // Insertion Sort
    memcpy(&aux, &hospital, sizeof(Hospital));
    insertionsort(&aux, &comp, &mov);
    printf("- Insertion.: %04d | %04d\n", comp, mov);

    return 0;
}
