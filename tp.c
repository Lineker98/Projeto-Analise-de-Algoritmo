#include "./algorithm/brute_force.h"
#include<string.h>
#include<stdbool.h>


void ler_pesos(int *n, int *pesos)
{
  int j;
  for (j = 0; j <= *n; j++)
  {
    scanf("%d", &pesos[j]);
  }
}

int main(int numargs, char *args[])
{
  int t, i = 0, j;
  int n, k, solution, *pesos;
  int PD = false, AG = false, FB = false;

  scanf("%d", &t);

  for(j=1; j < numargs; j++){
    if( strcmp(args[j], "FB") ){
      FB = true;
    }
    
    else if ( strcmp(args[j], "PD") ){
      PD = true;
    }

    else if ( strcmp(args[j], "AG") ){
      AG = true;
    }
  }

  do
  {
    
    scanf("%d %d", &n, &k);

    pesos = (int *)calloc(n + 1, sizeof(int));

    ler_pesos(&n, pesos);

    if( FB )
    {
      solution = brute_force(n, k, pesos);
      printf("%d\n", solution);
    }
    if ( PD )
    {
      /* code */
    }
    if ( AG )
    {
      /* code */
    }

    i = i + 1;

    free(pesos);

  } while (i < t);
  
  return 0;
}