#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int var = atoi(argv[1]);
  
  double potencia = pow(2, (double)(var)); 

  int parametro = potencia;
  printf("Matriz de %dx%d",parametro,parametro);
  printf("\nCom %d de números aleatórios dentro dela",parametro*parametro);
  printf("\n");

  srand(time(NULL));

  int *firstMatrix[parametro];
  int *secondMatrix[parametro];
  int finalMatrix[parametro][parametro];
  int some;
  int p1,p2;


    for (int i=0; i<parametro; i++){
      firstMatrix[i] = (int *)malloc(parametro * sizeof(int));
    }

    for (int i=0; i<parametro; i++){
      for (int z=0; z<parametro; z++){
        firstMatrix[i][z] = (int *)malloc(parametro * sizeof(int));
      }
    }

    for (int i=0; i<parametro; i++){
      secondMatrix[i] = (int *)malloc(parametro * sizeof(int));
    }

    for (int i=0; i<parametro; i++){
      for (int z=0; z<parametro; z++){
        secondMatrix[i][z] = (int *)malloc(parametro * sizeof(int));
      }
    }



  for (int i = 0; i < parametro; i++)
  {
    for (int j = 0; j < parametro; j++)
    {
      finalMatrix[i][j] = 0;
    }
    
  }

  for (int i = 0; i < parametro; i++)
  {
    for (int j = 0; j < parametro; j++)
    {
      firstMatrix[i][j] = rand() % 10;
    }
    
  }

  for (int i = 0; i < parametro; i++){
    for (int j = 0; j < parametro; j++){
      secondMatrix[i][j] = rand() % 10;
    }  
  }

    for (int y = 0; y < parametro; y++)
    {
      for (int x = 0; x < parametro; x++)
      {

        for (int z = 0; z < parametro; z++)
        {
          finalMatrix[y][x] += firstMatrix[y][z]*secondMatrix[z][x];
        }
        
      }

    }

    free(*firstMatrix);
    free(*secondMatrix);
    p1 = firstMatrix;
    p2 = secondMatrix;
    p1 = NULL;
    p2 = NULL;

  for (int y = 0; y < parametro; y++){
    for (int x = 0; x < parametro; x++){
      printf("%d ", finalMatrix[y][x]);
    }  
    printf("\n");
  }
  
  
  return 0;
}
