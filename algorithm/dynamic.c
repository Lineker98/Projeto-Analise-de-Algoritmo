#include "dynamic.h"

int dynamic_algorithm(int atual, int n, int k, int *path)
{
  int mat[atual + 1][n + 1][k + 1];
  int i, j, l;

  for (i = 0; i <= atual; i++)
  {
    for (j = 0; j <= k; j++)
    {
      mat[i][0][j] = 0;
    }
  }

  for (i = 0; i <= atual; i++)
  {
    for (j = 0; j <= n; j++)
    {
      mat[i][j][0] = travel_cost(0, i, path);
    }
  }

  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= k; j++)
    {
      for (l = 1; l <= atual; l++)
      {

        if (i <= j)
        {
          mat[l][i][j] = max(
            mat[i][i - 1][j - 1], 
            travel_cost(i, l, path)
          );
        }

        else
        {
          mat[l][i][j] = min(
              max(
                  mat[i][i - 1][j - 1],
                  travel_cost(i, l, path)
                ),

              max(
                  mat[l][i - 1][j],
                  travel_cost(i - 1, l, path)
                )
          );
        }
      }
    }
  }

  // for (int i = 0; i <= n; i++)
  // {
  //   for (int j = 0; j <= k; j++)
  //   {
  //     printf("[");
  //     for (int l = 1; l <= atual; l++)
  //     {
  //       printf(" %d ", mat[l][i][j]);
  //     }
  //     printf("], ");
  //   }
  //   printf("\n");
  // }

  return mat[atual][n][k];
}

int dynamic_recorrencia(int atual, int n, int k, int *path)
{
  if (k == 0)
  {
    return travel_cost(0, atual, path);
  }

  else if (n == 0)
  {
    return 0;
  }

  else if (n <= k)
  {
    return max(
        travel_cost(n, atual, path),
        dynamic_recorrencia(n, n - 1, k - 1, path)
    );
  }

  int maxL =
      max(
          travel_cost(n, atual, path),
          dynamic_recorrencia(n, n - 1, k - 1, path)
      );

  int maxL1 =
      max(
          travel_cost(n - 1, atual, path),
          dynamic_recorrencia(atual, n - 1, k, path)
      );

  return min(
      maxL,
      maxL1
  );
}