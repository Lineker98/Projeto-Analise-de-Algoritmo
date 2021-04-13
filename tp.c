#include "./algorithm/brute_force.h"
#include "./algorithm/guloso.h"
#include "./algorithm/dynamic.h"
#include "./libraries/input_function.h"
#include <time.h>

int main(int numargs, char *args[])
{
  int t, i = 0;
  int n, k, solution, *pesos;
  clock_t tempo;
  double tempo_gasto;

  scanf("%d", &t);

  int algorithm = choose_algorithm(numargs, args);

  do
  {
    scanf("%d %d", &n, &k);

    pesos = (int *)calloc(n + 1, sizeof(int));

    read_path(n, pesos);

    switch (algorithm)
    {
    case 1:
      tempo = clock();
      solution = brute_force(n, k, pesos);
      tempo = clock() - tempo;
      tempo_gasto = (double)(tempo)*1000 / CLOCKS_PER_SEC;
      printf("%d %d %d %f \n", n, k, solution, tempo_gasto);
      break;

    case 2:
      tempo = clock();
      solution = guloso(n, k, pesos);
      tempo = clock() - tempo;
      tempo_gasto = (double)(tempo)*1000 / CLOCKS_PER_SEC;
      printf("%d %d %d %f \n", n, k, solution, tempo_gasto);
      break;

    case 3:
      tempo = clock();
      solution = dynamic_algorithm(n + 1, n, k, pesos);
      tempo = clock() - tempo;
      tempo_gasto = (double)(tempo)*1000 / CLOCKS_PER_SEC;
      printf("%d %d %d %f \n", n, k, solution, tempo_gasto);
      break;
    }

    i = i + 1;
    free(pesos);

  } while (i < t);

  return 0;
}