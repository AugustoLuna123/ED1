#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int recursaoPotencia(int base, int expoente);

int recursaoPotencia(int base, int expoente){
    
    if(expoente == 1){
        return base;
    }

    return base * recursaoPotencia(base, expoente -1);

}
int main (){

    int x = 3, y = 3;
    //double z = 5, w = 5;

    //printf("%.2lf", pow(z, w));
    printf("%d", recursaoPotencia(x, y));
    printf("\n");
    return 0;
}

