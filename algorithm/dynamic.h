#ifndef DYNAMIC_H
#define DYNAMIC_H

#include "../libraries/planet.h"
#include "../libraries/matrix.h"

int dynamic_algorithm(int atual, int n, int k, int *path);
/*
  Entrada: atual --> o planeta atual, iniciado por n+1
           n --> numero de planetas possíveis
           k --> número de planetas a serem conquistados
           path --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar k planetas de forma ótima
  */

int dynamic_recorrencia(int atual, int n, int k, int *path);
/*
  Entrada: atual --> o planeta atual, iniciado por n+1
           n --> numero de planetas possíveis
           k --> número de planetas a serem conquistados
           path --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar k planetas de forma ótima
  */

#endif  