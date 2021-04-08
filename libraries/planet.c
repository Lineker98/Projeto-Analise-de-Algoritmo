#include "planet.h"

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

int travel_cost(int start, int end, int *path)
{
  int value = 0;

  for (int j = start; j < end; j++)
  {
    value += path[j];
  }

  return value;
}
