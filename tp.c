#include "./algorithm/brute_force.h"
#include "./algorithm/guloso.h"
#include "./libraries/input_function.h"

int max(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int min(int a, int b)
{
  if (a < b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int summation(int start, int end, int *vector)
{
  int i, aux = 0;

  for (i = start; i < end; i++)
  {
    aux += vector[i];
  }

  return aux;
}

int dynamic_algorithm(int n, int k, int p, int start, int size, int *paths)
{
  //printf("n = %d, k = %d, p = %d start = %d\n", n, k, p, start);

  if (k == 0)
  {
    // printf("sumation = %d\n", summation(0, start, paths));
    p = max(
        p, summation(0, start, paths));
    // printf("max = %d\n", p);
    return p;
  }

  if (n <= k)
  {
    return dynamic_algorithm(
        n - 1,
        k - 1,
        max(p, summation(n, start, paths)),
        n,
        size,
        paths);
  }

  return min(dynamic_algorithm(
                 n - 1,
                 k - 1,
                 max(p, summation(n, start, paths)),
                 n,
                 size,
                 paths),

             dynamic_algorithm(
                 n - 1,
                 k,
                 max(p, summation(n - 1, start, paths)),
                 start,
                 size,
                 paths));
}

int main(int numargs, char *args[])
{
  int t, i = 0;
  int n, k, solution, *pesos;

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
      solution = brute_force(n, k, pesos);
      printf("%d\n", solution);
      break;

    case 2:
      solution = guloso(n, k, pesos);
      printf("%d\n", solution);
      break;

    case 3:
      solution = dynamic_algorithm(n, k, 0, n + 1, n + 1, pesos);
      printf("%d\n", solution);

      break;
    }

    i = i + 1;
    free(pesos);

  } while (i < t);

  return 0;
}