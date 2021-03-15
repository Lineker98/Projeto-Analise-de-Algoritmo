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

    //n = (int *) calloc(t, sizeof(int));
    //k = (int *) calloc(t, sizeof(int));

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

    } while (i < t);



    /*
    int *p;
    p = (int *) malloc(5*sizeof(int));
    int i;
    for(i = 0; i < 5; i++){
        printf("\nDigite p[%d]: ", i);
        scanf("%d", &p[i]);
    }
    for(i = 0; i < 5; i++){
        printf("\np[%d] = %d ", i, p[i]);
    }

    p = (int *) realloc(p, 7*sizeof(int));
    for(i = 5; i < 7; i++){
        printf("\nDigite p[%d]: ", i);
        scanf("%d", &p[i]);
    }
    for(i = 0; i < 7; i++){
        printf("\np[%d] = %d ", i, p[i]);
    }

    free(p);*/

    return 0;
}