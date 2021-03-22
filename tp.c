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

int main(int numargs, char *args[])
{
  int t, i = 0;
  int n, k, solution, *pesos;


  scanf("%d", &t);

  do
  {
    scanf("%d %d", &n, &k);

    pesos = (int *)calloc(n + 1, sizeof(int));

    ler_pesos(&n, pesos);

    //solution = brute_force(n, k, pesos);
    //printf("%d\n", solution);
    solution = guloso(n, k, pesos);
    printf("%d\n", solution);
    i = i + 1;

    free(pesos);

  } while (i < t);

  return 0;
}