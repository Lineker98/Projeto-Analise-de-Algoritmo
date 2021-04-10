#include "guloso.h"

int guloso(int n, int k, int* path)
{

    /*
        Para as k's possíveis escolhas dentre os n planetas, dado que
        sempre escolhemos a chegada, foram criadas então duas estruturas de dados
        auxiliares: peso_planetas = array de n posições onde em cada índice é
        armazenado o peso (aresta anterior + aresta posterior) do planeta respectivo,
        planetas_escolhidos = array de n + 1 posições, inicialmente preenchido com 0's
        até a posição n, sendo alterado em memória de 0 para 1 de acordo os k's
        planetas mais pesados.

        Escolha gulosa: Sempre passamos pelos planetas escolhidos, ou, mais pesados.
        Saída: Meior distância aproximada para conquistar os k's planetas.

    */

    int i, max = 0, soma1 = 0;
    int *peso_planeta, *planetas_escolhidos;

    peso_planeta = (int *) calloc(n, sizeof(int));
    planetas_escolhidos = (int *) calloc(n+1, sizeof(int));
    planetas_escolhidos[n] = 1;

    // Cálculo do peso de cada planeta.
    for(i = 0; i < n; i++){
        peso_planeta[i] = path[i] + path[i+1];
        planetas_escolhidos[i] = 0;
    }

    // Escolha gulosa
    for(i = 0; i < k; i++){
        esolhe_planeta(&n, peso_planeta, planetas_escolhidos);
    }

    // Cálculo do maior caminho percorrido, dado os planetas escolhidos
    // pela escolha gulosa.
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