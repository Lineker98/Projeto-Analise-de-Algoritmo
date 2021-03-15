#include<stdio.h>
#include<stdlib.h>

void ler_pesos(int *n, int *pesos){

    int j;

    for(j=0; j <= *n; j++){
            scanf("%d", &pesos[j]);
        }
}

int main(int numargs, char *args[]){

    int t, i = 0, j;
    int n, k, *pesos;

    scanf("%d", &t);
    printf("%d\n", t); 


    do{
        scanf("%d %d", &n, &k);
        printf("%d %d\n", n, k); 
        
        pesos = (int *) calloc(n + 1, sizeof(int));

        ler_pesos(&n, pesos);

        // Chama dos algoritmos de resolução

        // Verificar os pesos
        for(j=0; j <= n; j++){
            printf("%d\n", pesos[j]);
        }

        i = i + 1;
        free(pesos);

    } while (i < t);


    return 0;
}