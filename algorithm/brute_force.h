#ifndef FORCABRUTA_H
#define FORCABRUTA_H

#include "../libraries/combination.h"
#include "../libraries/planet.h"

int brute_force(int n, int k, int* path);
/*
  Entrada: n --> numero de planetas possíveis
           k --> número de planetas a serem conquistados
           path --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar k planetas de forma ótima
  */

#endif  