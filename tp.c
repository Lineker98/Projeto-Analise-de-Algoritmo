#include<stdio.h>
#include<stdlib.h>

void ler_pesos(int *qtd_planetas, int *pesos){

    int j;

    for(j=0; j <= *qtd_planetas; j++){
            scanf("%d", &pesos[j]);
        }
}

int main(int numargs, char *args[]){

    int instancias, i = 0, j;
    int *qtd_planetas, *max_conquistados, *pesos;

    scanf("%d", &instancias);
    printf("%d\n", instancias); 

    qtd_planetas = (int *) calloc(instancias, sizeof(int));
    max_conquistados = (int *) calloc(instancias, sizeof(int));

    do{
        scanf("%d %d", &qtd_planetas[i], &max_conquistados[i]);
        printf("%d %d\n", qtd_planetas[i], max_conquistados[i]); 
        
        pesos = (int *) calloc(qtd_planetas[i] + 1, sizeof(int));

        ler_pesos(&qtd_planetas[i], pesos);

        // Chama dos algoritmos de resolução

        // Verificar os pesos
        for(j=0; j <= qtd_planetas[i]; j++){
            printf("%d\n", pesos[j]);
        }

        i = i + 1;

    } while (i < instancias);



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