#ifndef COMBINATION_H
#define COMBINATION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_binary(unsigned int number);

int number_of_bits_1(unsigned long long int max, unsigned long long int num);

int *return_combination(unsigned long long int c, int array[]);

#endif