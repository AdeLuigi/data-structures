#include <time.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{

  srand(time(NULL));

  int firstMatrix[500][500];
  int secondMatrix[500][500];
  int finalMatrix[500][500];
  int some;


  for (int i = 0; i < 500; i++)
  {
    for (int j = 0; j < 500; j++)
    {
      finalMatrix[i][j] = 0;
    }
    
  }

  for (int i = 0; i < 500; i++)
  {
    for (int j = 0; j < 500; j++)
    {
      firstMatrix[i][j] = rand() % 10;
    }
    
  }

  for (int i = 0; i < 500; i++){
    for (int j = 0; j < 500; j++){
      secondMatrix[i][j] = rand() % 10;
    }  
  }

    for (int y = 0; y < 500; y++)
    {
      for (int x = 0; x < 500; x++)
      {

        for (int z = 0; z < 500; z++)
        {
          finalMatrix[y][x] += firstMatrix[y][z]*secondMatrix[z][x];
        }
        
      }

    }


  
  
  return 0;
}
