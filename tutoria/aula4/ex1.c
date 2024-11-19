#include <stdio.h>
#include <string.h>

int encaixa(char A[], char B[], int tamA, int tamB, int idxA, int idxB) {
    if (idxB == tamB)
        return 1;
    if (idxA == tamA)
        return 0;
    if (A[tamA - 1 - idxA] != B[tamB - 1 - idxB])
        return 0;
    return encaixa(A, B, tamA, tamB, idxA + 1, idxB + 1);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char A[1001], B[1001];
        scanf("%s %s", A, B);
        
        int tamA = strlen(A);
        int tamB = strlen(B);
        
        if (encaixa(A, B, tamA, tamB, 0, 0))
            printf("encaixa\n");
        else
            printf("nao encaixa\n");
    }
    
    return 0;
}
