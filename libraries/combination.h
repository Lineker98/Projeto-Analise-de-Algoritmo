#ifndef COMBINATION_H
#define COMBINATION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_binary(unsigned int number);
/*
  Entrada: number --> número inteiro
  Saida: representação binária do número.
  */

int number_of_bits_1(int max, int num);
/*
  Entrada: max --> maior número representado pela quantidade de bits
           num --> número a ser avaliado

  Saida: Quantidade de bits 1s que a forma binaria do num possui.
  */

int *return_combination(int c, int array[]);
/*
  Entrada: c --> número binário que representa a combinação
           array --> lista dos planetas.

  Saida: Uma nova lista apenas com os planetas que foram escolhidos
  por c, ou seja, serão retornados os valores do array de entrada que
  estiverem na posição em que o bit de c for 1.
  */

#endif