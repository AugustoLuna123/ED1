#include<stdio.h>
#include<stdlib.h>
#include <string.h>


void inverteString (char string[]){
    
    
    if(string[0] == '\0'){

    return;
    }

    inverteString( &string[1]);
    printf("%c", string[0]);
}

int main (){

    char nome[] = "Augusto";

    inverteString(nome);

    printf("\n");

    
return 0;
}