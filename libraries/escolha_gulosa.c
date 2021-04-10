#include "escolha_gulosa.h"

void esolhe_planeta(int *n, int *peso_planeta, int *planetas_escolhidos){

    /*
    Para as k's possíveis escolhas de planetas, percorremos o array planetas_escolhidos
    de forma que, em cada iteração, esolhemos o planeta mais pesado, se este ainda não
    estiver escolhido, e alteramos em memória seu índex correspondente
    em planetas_escolhidos de 0 -> 1.
    */

    int max = -1, indice = -1;

    for(int i = 0; i<*n; i++)
    {
        if(peso_planeta[i] > max && planetas_escolhidos[i] != 1){
            max = peso_planeta[i];
            indice = i;
        }

    }

    planetas_escolhidos[indice] = 1;

    return;
}
