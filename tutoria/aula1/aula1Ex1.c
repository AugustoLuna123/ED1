#include <stdio.h>

int fibonacci(int n) {
    
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    printf("Digite o valor de n para calcular o n-ésimo número de Fibonacci: ");
    scanf("%d", &n);

    printf("O %d-ésimo número de Fibonacci é: %d\n", n, fibonacci(n));

    return 0;
}
