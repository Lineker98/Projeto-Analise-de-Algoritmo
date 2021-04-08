#include "planet.h"

int max(int a, int b)
{
  /*
  Entrada: a --> numero inteiro
           b --> numero

  Saida: retorna o maior valor entre a e b
  */

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
  /*
  Entrada: a --> numero inteiro
           b --> numero

  Saida: retorna o menor valor entre a e b
  */

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
  /*
  Entrada: start --> planeta inicial
           array --> planeta final

  Saida: retorna o custo de se viajar do planeta start até o planeta 
  end (não incluso).
  */

  int value = 0;

  for (int j = start; j < end; j++)
  {
    value += path[j];
  }

  return value;
}
