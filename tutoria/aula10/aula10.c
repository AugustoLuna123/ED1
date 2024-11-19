#include <stdbool.h>
#include <stdio.h>

bool insertionSort(int *vetor, int tam) {
  // implemente aqui sua solução

  for(int i = 1; i<tam; i++){
    int aux = vetor[i];
    int j = i-1;
    while(j >= 0 && aux < vetor[j]){
        vetor[j+1] = vetor[j];
         j = j-1;
    }
    vetor[j+1] = aux;
  }

  return true;
}

bool insertioSortDescrescente(int *vetor, int tam){
    for(int i = 1; i<tam; i++){
        int aux = vetor[i];
        int j = i-1;

        while(j >=0 && aux > vetor[j]){
            vetor[j+1] = vetor[j];
            j = j - 1;

        }
        vetor[j+1] = aux;
    }
    return true;
}

// implemente aqui a solução do exercício 4
bool selectionSort(int *vetor, int tam) {
//    implemente aqui sua solução
    for (int i = 0; i<tam; i++){
        int min = i;
        for(int j = i + 1; j< tam; j++){
            if(vetor[j]< vetor[min]){
                min = j;
            }
        }
        int aux  = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;

    }

    return true;

}



int main() {
  int vetor[] = {31, 41, 59, 26, 41, 58};
  int tam = 6;

  //insertionSort(vetor, tam);
  //insertioSortDescrescente(vetor, tam);
  selectionSort(vetor, tam);

  for (int i = 0; i < tam; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  printf("59 58 41 41 31 26 <- Resultado esperado\n");
  return 0;
}