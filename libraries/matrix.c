#include "./matrix.h"

int ***make_matrix(int n, int k)
{
  int atual = n + 1;
  int ***mat;

  int a = atual + 1;
  int b = n + 1;
  int c = k + 1;

  int i, j;

  mat = (int ***)malloc(a * sizeof(int *));

  for (i = 0; i < a; i++)
  {
    mat[i] = (int **)malloc(b * sizeof(int *));
  }

  for (i = 0; i < a; i++)
  {
    for (j = 0; j < b; j++)
    {
      mat[i][j] = (int *)malloc(c * sizeof(int *));
    }
  }

  return mat;
}

void free_matrix(int ***mat, int n)
{
  int a = n + 2;
  int b = n + 1;
  int i, j;

  for (i = 0; i < a; i++)
  {
    for (j = 0; j < b; j++)
    {
      free(mat[i][j]);
    }
  }
  for (i = 0; i < a; i++)
  {
    free(mat[i]);
  }

  free(mat);
}