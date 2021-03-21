#include "guloso.h"

void esolhe_planeta(int n, int *peso_planeta, int *planetas_escolhidos){

    int max = peso_planeta[0], indice = 0;

    for(int i = 1; i<n; i++)
    {
        if(peso_planeta[i] > max && planetas_escolhidos[i] != 1){
            max = peso_planeta[i];
            indice = i;
        }

    }

    planetas_escolhidos[indice] = 1;

    return;
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

    for(i = 0; i < k; i++){

        esolhe_planeta(n, peso_planeta, planetas_escolhidos);

    }
}