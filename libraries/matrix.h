#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

int ***make_matrix(int n, int k);

void free_matrix(int ***mat, int n);

#endif