#include "combination.h"

void print_binary(unsigned int number)
{
  if (number >> 1)
  {
    print_binary(number >> 1);
  }

  printf("%d", number & 1);
}

int number_of_bits_1(int max, int num)
{
  int mask = 1;
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

int *return_combination(int c, int array[])
{
  int i = 0, j = 0;
  int mask = 1;
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