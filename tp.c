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
  int t, i = 0;
  int n, k, solution, *pesos;
  bool PD = false, AG = false, FB = false;

  scanf("%d", &t);


  for(i=1; i < numargs; i++){
    if( strcmp(args[i], "FB") ){
      FB = true;
    }
    
    else if ( strcmp(args[i], "PD") ){
      PD = true;
    }

    else if ( strcmp(args[i], "AG") ){
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
    else if ( PD )
    {
      /* code */
    }
    else if ( AG )
    {
      /* code */
    }
    
    
    i = i + 1;

    free(pesos);
    

  } while (i < t);

  return 0;
}