#include "./algorithm/brute_force.h"
#include "./algorithm/guloso.h"

void ler_pesos(int *n, int *pesos)
{
  int j;
  for (j = 0; j <= *n; j++)
  {
    scanf("%d", &pesos[j]);
  }
}


void escolhe_algoritmos(int *numargs, char *args[], bool *PD, bool *AG, bool *FB)
{

  int j;

  for(j=1; j < *numargs; j++){
    if( strcmp(args[j], "FB") == 0 ){
      *FB = true;
    }
    
    if( strcmp(args[j], "PD") == 0 ){
      *PD = true;
    }

    if( strcmp(args[j], "AG") == 0){
      *AG = true;
    }
  }
}


int main(int numargs, char *args[])
{
  int t, i = 0;
  int n, k, solution, *pesos;
  bool PD = false, AG = false, FB = false;


  scanf("%d", &t);

  escolhe_algoritmos(&numargs, args, &PD, &AG, &FB);

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