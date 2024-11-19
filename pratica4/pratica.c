#include "seno.h"
#include <stdio.h>

int main() {
    int x, n;
    scanf("%d", &x);
    scanf("%d", &n);
    
    double resultado = seno(x, n);
    printf("%f\n", resultado);
    
    return 0;
}
