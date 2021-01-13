#include <time.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{

  srand(time(NULL));

  int *firstMatrix[2000];
  int *secondMatrix[2000];
  int finalMatrix[2000][2000];
  int some;
  int p1,p2;

    for (int i=0; i<2000; i++){
      firstMatrix[i] = (int *)malloc(2000 * sizeof(int));
    }

    for (int i=0; i<2000; i++){
      secondMatrix[i] = (int *)malloc(2000 * sizeof(int));
    }



  for (int i = 0; i < 2000; i++)
  {
    for (int j = 0; j < 2000; j++)
    {
      finalMatrix[i][j] = 0;
    }
    
  }

  for (int i = 0; i < 2000; i++)
  {
    for (int j = 0; j < 2000; j++)
    {
      firstMatrix[i][j] = rand() % 10;
    }
    
  }

  for (int i = 0; i < 2000; i++){
    for (int j = 0; j < 2000; j++){
      secondMatrix[i][j] = rand() % 10;
    }  
  }

    for (int y = 0; y < 2000; y++)
    {
      for (int x = 0; x < 2000; x++)
      {

        for (int z = 0; z < 2000; z++)
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
  
  
  return 0;
}
