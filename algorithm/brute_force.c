#include "brute_force.h"

int brute_force(int n, int k, int* path)
{
  int planets[n];

  for (int i = 0; i < n; i++)
  {
    planets[i] = i;
  }

  int max_combination = pow(2, n) - 1;
  int size_combination;

  int *combination;
  int start;
  int end;
  int value;

  int min_global = (int)INFINITY;
  int max_local;

  for (int i = 0; i <= max_combination; i++)
  {
    start = 0;
    end = 0;
    max_local = -1;

    size_combination = number_of_bits_1(max_combination, i);

    if (size_combination == k)
    {
      combination = return_combination(i, planets);

      for (int z = 0; z < k; z++)
      {
        end = combination[z];
        value = travel_cost(start, end + 1, path);

        //printf("%d\n", value);
        if (value > max_local)
        {
          max_local = value;
        }

        start = combination[z] + 1;
      }

      end = n;
      value = travel_cost(start, end + 1, path);

      if (value > max_local)
      {
        max_local = value;
      }

      if(max_local < min_global){
        min_global = max_local;
      }
      free(combination);
    }
  }
  
  return min_global;
}
