#include "planet.h"

int travel_cost(int start, int end, int *path)
{
  int value = 0;

  for (int j = start; j <= end; j++)
  {
    value += path[j];
  }

  return value;
}