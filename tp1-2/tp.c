#include <stdio.h>                    
#include <stdlib.h>                  
#include "automato.h"                 
#include <allegro5/allegro.h>        
#include <allegro5/allegro_primitives.h> 

#define CELL_SIZE 50                  

void desenharMatriz(AutomatoCelular *automato); 

void desenharMatriz(AutomatoCelular *automato) {
    
    for (int i = 0; i < automato->dimensao; i++) {
        for (int j = 0; j < automato->dimensao; j++) {
            if (automato->grade[i][j] == 1) { //se for uma celular viva desenha um quadrado preto
                al_draw_filled_rectangle(j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, al_map_rgb(0, 0, 0));
            } else { // se for uma celula morta, quadrado branco
                al_draw_rectangle(j * CELL_SIZE, i * CELL_SIZE, (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE, al_map_rgb(0, 0, 0), 1.0); 
            }
        }
    }
}

int main() {
    ALLEGRO_DISPLAY *display = NULL;   // inicializando um display do allegro

    int dimensao, geracoes;         
    scanf("%d", &dimensao);           
    scanf("%d", &geracoes);            

    AutomatoCelular *automato = alocarReticulado(dimensao, geracoes);

    leituraReticulado(automato);     

    if (!al_init()) {  //inicializa a biblioteca do allegro e verifica se foi bem sucedido. (falha caso a entrada não seja do tipo correto)
        fprintf(stderr, "Falha ao inicializar o Allegro.\n"); 
        return -1;                     
    }

    display = al_create_display(CELL_SIZE * dimensao, CELL_SIZE * dimensao); // cria a janela

    al_init_primitives_addon(); 

    for (int i = 0; i < geracoes; i++) { 
        evoluirReticulado(automato, 1);
        al_clear_to_color(al_map_rgb(255, 255, 255)); 
        desenharMatriz(automato);       // aplica a interface na matriz
        al_flip_display();              // atualiza a exibição da janela.
        al_rest(1);                     // tempo entre gerações
    }
    
    al_rest(20);                         // tempo de duração da janela
    printf("\n");                     
    imprimeReticulado(automato);       
    desalocarReticulado(automato);     
    return 0;                           
}
