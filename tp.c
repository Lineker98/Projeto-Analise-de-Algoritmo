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

int dynamic_algorithm2(int n, int k, int *paths)
{
  int mat[n + 1][k + 1];
  int i;

  for (i = 0; i <= k; i++)
  {
    mat[0][i] = 0;
  }

  for (i = 1; i <= n; i++)
  {
    mat[i][0] = summation(0, i, paths);
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= k; j++)
    {

      if (i <= j)
      {
        mat[i][j] = max(mat[i - 1][j - 1], paths[i - 1]);
      }

      else
      {
        mat[i][j] = min(
            max(
                mat[i - 1][j - 1],
                paths[i]

                ),

            max(
                mat[i - 1][j],
                paths[i] + paths[i - 1]

                )

        );
      }
    }
  }

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      printf(" [%d] ", mat[i][j]);
    }
    printf("\n");
  }

  return mat[n][k];
}

int dynamic_algorithm(int atual, int n, int k, int *path)
{

  //printf("atual = %d n = %d k = %d\n", atual, n, k);

  if (k == 0)
  {
    return summation(0, atual, path);
  }

  else if (n == 0)
  {
    return 0;
  }

  else if (n <= k)
  {
    return max(
        summation(n, atual, path),
        dynamic_algorithm(n, n - 1, k - 1, path)

    );
  }

  int maxL =
      max(
          summation(n, atual, path),
          dynamic_algorithm(n, n - 1, k - 1, path)

      );

  int maxL1 =
      max(
          summation(n - 1, atual, path),
          dynamic_algorithm(atual, n - 1, k, path)

      );

  return min(
      maxL,
      maxL1

  );
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
      solution = dynamic_algorithm(n + 1, n, k, pesos);
      printf("%d\n", solution);

      break;
    }

    i = i + 1;
    free(pesos);

  } while (i < t);

  return 0;
}