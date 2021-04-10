#include<stdio.h>
#include<stdlib.h>

void esolhe_planeta(int *n, int *peso_planeta, int *planetas_escolhidos);
    /*
    Entradas:
            n --> Número de planetas + 1, considerando o destino final.
            peso_planeta --> Array com peso de cada planeta, onde o peso é
                            calculado pela aresta anterior + aresta posterior.
            planetas_escolhidos --> Array de zeros com n posições.
    
    Saida: 
        Alteração em memória de 0 -> 1 do conteúdo de planetas_escolhidos
        para os planetas mais pesados
    */

