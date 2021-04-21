#ifndef PLANET_H
#define PLANET_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int travel_cost(int start, int end, int *path);
/*
  Entrada: start --> planeta inicial
           array --> planeta final

  Saida: retorna o custo de se viajar do planeta start até o planeta 
  end (não incluso).
  */

int max(int a, int b);
/*
  Entrada: a --> numero inteiro
           b --> numero

  Saida: retorna o maior valor entre a e b
  */

int min(int a, int b);
/*
  Entrada: a --> numero inteiro
           b --> numero

  Saida: retorna o menor valor entre a e b
  */

#endif