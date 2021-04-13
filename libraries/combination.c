#include "combination.h"

void print_binary(unsigned int number)
{
  /*
  Entrada: number --> número inteiro
  Saida: representação binária do número.
  */

  if (number >> 1)
  {
    print_binary(number >> 1);
  }

  printf("%d", number & 1);
}

int number_of_bits_1(unsigned long long int max, unsigned long long int num)
{
  /*
  Entrada: max --> maior número representado pela quantidade de bits
           num --> número a ser avaliado

  Saida: Quantidade de bits 1s que a forma binaria do num possui.
  */
  unsigned long long int mask = 1;
  int k = 0;

  while (max > 0)
  {
    if (num & mask)
    {
      k++;
    }

    mask = mask << 1;
    max--;
  }

  return k;
}

int *return_combination(unsigned long long int c, int array[])
{
  /*
  Entrada: c --> número binário que representa a combinação
           array --> lista dos planetas.

  Saida: Uma nova lista apenas com os planetas que foram escolhidos
  por c, ou seja, serão retornados os valores do array de entrada que
  estiverem na posição em que o bit de c for 1.
  */

  int i = 0, j = 0;
  unsigned long long int mask = 1;
  int max = (int)floor(log2(c) + 1);

  int *combination = (int *)malloc(max * sizeof(int));

  while (max > 0)
  {
    if (c & mask)
    {
      combination[j] = array[i];
      j++;
    }

    mask = mask << 1;
    i++;
    max--;
  }

  return combination;
}