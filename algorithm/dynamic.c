#include "dynamic.h"

int dynamic_algorithm(int atual, int n, int k, int *path)
{
  /*
  Entrada: atual --> o planeta atual, iniciado por n+1
           n --> numero de planetas possíveis
           k --> número de planetas a serem conquistados
           path --> peso das viagens entre os planetas
  
  Saida: valor do maior caminho para conquistar k planetas de forma ótima

  Basendo na recorrência (função dynamic_recorrencia logo em baixo desse
  script) utilizou-se a técnica da programação dinamica para resolver o ploblema. 
  De forma que i representou a variação de n, j a variação de k e l a variação do
  atual.
  */

  int ***mat = make_matrix(n, k); //[atual + 1][n + 1][k + 1];
  int i, j, l;

  for (i = 0; i <= atual; i++)
  {
    for (j = 0; j <= k; j++)
    {
      mat[i][0][j] = 0;
    }
  }

  for (i = 0; i <= atual; i++)
  {
    for (j = 0; j <= n; j++)
    {
      mat[i][j][0] = travel_cost(0, i, path);
    }
  }

  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= k; j++)
    {
      for (l = 1; l <= atual; l++)
      {

        if (i <= j)
        {
          mat[l][i][j] = max(
              mat[i][i - 1][j - 1],
              travel_cost(i, l, path));
        }

        else
        {
          mat[l][i][j] = min(
              max(
                  mat[i][i - 1][j - 1],
                  travel_cost(i, l, path)),

              max(
                  mat[l][i - 1][j],
                  travel_cost(i - 1, l, path)));
        }
      }
    }
  }

  int answer = mat[atual][n][k];
  free_matrix(mat,n); 

  return answer;
}

int dynamic_recorrencia(int atual, int n, int k, int *path)
{
  /*
  Entrada: atual --> o planeta atual, iniciado por n+1
           n --> numero de planetas possíveis
           k --> número de planetas a serem conquistados
           path --> peso das viagens entre os planetas
  
  Saida: valor do maio caminho para conquistar k planetas de forma ótima

  Para o programação dinâmica criamos essa recorrência que segue a seguinte 
  lógica:
    se k = 0, já foi conquistado todos os planetas possíveis;
    se n = 0, não tem planeta para ser conquistado
    se n <=k, eu preciso conquistar o próximos planetas
    caso o contrátio, avalio se é melhor conquistar o planeta ou pular ele.
  */

  if (k == 0)
  {
    return travel_cost(0, atual, path);
  }

  else if (n == 0)
  {
    return 0;
  }

  else if (n <= k)
  {
    return max(
        travel_cost(n, atual, path),
        dynamic_recorrencia(n, n - 1, k - 1, path));
  }

  int maxL =
      max(
          travel_cost(n, atual, path),
          dynamic_recorrencia(n, n - 1, k - 1, path));

  int maxL1 =
      max(
          travel_cost(n - 1, atual, path),
          dynamic_recorrencia(atual, n - 1, k, path));

  return min(
      maxL,
      maxL1);
}