#include "guloso.h"

int esolhe_planeta(int n, int peso_planeta[], int max_anterior){

    int max = peso_planeta[0], indice = 0;

    for(int i = 1; i<n; i++)
    {
        if(peso_planeta[i] > max && i != max_anterior){
            max = peso_planeta[i];
            indice = i;
        }

    }

    return indice;
}

void guloso(int n, int k, int* path)
{

    int i;
    int *peso_planeta, *planetas_escolhidos;

    peso_planeta = (int *) calloc(n - 1, sizeof(int));
    planetas_escolhidos = (int *) calloc(n, sizeof(int));

    for(i = 0; i < n; i++){
        peso_planeta[i] = path[i] + path[i+1];
        planetas_escolhidos[i] = 0;
    }

    
}