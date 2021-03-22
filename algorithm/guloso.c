#include "guloso.h"

void esolhe_planeta(int *n, int *peso_planeta, int *planetas_escolhidos){

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


int guloso(int n, int k, int* path)
{

    int i, max = 0, soma1 = 0;
    int *peso_planeta, *planetas_escolhidos;

    peso_planeta = (int *) calloc(n, sizeof(int));
    planetas_escolhidos = (int *) calloc(n+1, sizeof(int));
    planetas_escolhidos[n] = 1;

    for(i = 0; i < n; i++){
        peso_planeta[i] = path[i] + path[i+1];
        planetas_escolhidos[i] = 0;
    }

    // Escolha gulosa
    for(i = 0; i < k; i++){
        esolhe_planeta(&n, peso_planeta, planetas_escolhidos);
    }

    for(i = 0; i <= n; i++)
    {
        if(planetas_escolhidos[i]){
            soma1 = soma1 + path[i];

            if(soma1 > max){
                max = soma1;
            }

            soma1 = 0;
        }
        else{
            soma1 = soma1 + path[i];
        }
        
    }

    free(peso_planeta);
    free(planetas_escolhidos);

    return max;

}