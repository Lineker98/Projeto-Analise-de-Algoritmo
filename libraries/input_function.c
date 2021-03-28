#include "input_function.h"

void read_path(int n, int *pesos)
{
  int j;

  for (j = 0; j <= n; j++)
  {
    scanf("%d", &pesos[j]);
  }
}

int choose_algorithm(int numargs, char *args[])
{
  int j;

  for (j = 1; j < numargs; j++)
  {
    if (strcmp(args[j], "FB") == 0)
    {
      return 1;
    }

    else if (strcmp(args[j], "AG") == 0)
    {
      return 2;
    }

    else if (strcmp(args[j], "PD") == 0)
    {
      return 3;
    }
  }

  return 0;
}