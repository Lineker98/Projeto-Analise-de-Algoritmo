#include "brute_force.h"

int brute_force(int n, int k, int *path)
{
  /*
  Entrada: n --> numero de planetas possíveis
           k --> número de planetas a serem conquistados
           path --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar k planetas de forma ótima

  Para o força bruta utilizamos a ideia de combinações tomados k planetas,
  para identificar esses combinações utilizamos sequêcias de números binarios
  que contiam k quantidades de 1s. Ou seja, supondo que gostariamos de conquistar
  2 planetas dentre 3 possíveis, as possibilidades seriam: [011, 101, 110]. Após isso,
  avaliamos maior custo de cada uma dessas viagens e encontramos aquele que seja ótima.
  */

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

      if (max_local < min_global)
      {
        min_global = max_local;
      }
      free(combination);
    }
  }

  return min_global;
}
