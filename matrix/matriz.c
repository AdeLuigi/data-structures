#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>



void mostra(int ** Mat, int n)

{

		for(int i=0;i<n;i++){
        printf("\n");
       		 for(int j=0;j<n;j++)
           		 printf("%d ",Mat[i][j]);
    	}
    	printf("\n");
}

int** iniciaMatriz(int n)
{

	int** Mat;
	Mat=(int**)calloc(n,sizeof(int*));

	for(int i=0;i<n;i++){
            *(Mat+i)=(int*)calloc(n,sizeof(int));
            for(int j=0;j<n;j++){
            			Mat[i][j]=rand() % 1000;
            }
    }
    return  Mat;
}


int ** adiciona (int ** M1, int ** M2, int n) { 
    int ** temp = iniciaMatriz (n); 
    for (int i = 0; i <n; i ++) 
        for (int j = 0; j <n; j ++) 
            temp [i] [j] = M1 [i] [j] + M2 [i] [j]; 
    return temp;
}


int ** subtrai (int ** M1, int ** M2, int n) { 
    int ** temp = iniciaMatriz (n); 
    for (int i = 0; i <n; i ++) 
        for (int j = 0; j <n; j ++) 
            temp [i] [j] = M1 [i] [j] - M2 [i] [j]; 
    return temp; 
}



int **Strassen (int **A,int** B,int n){



if (n == 1) { 
    int ** C = iniciaMatriz (1); 
    C [0] [0] = A [0] [0] * B [0] [0]; 
    return C; 
}


int ** C = iniciaMatriz (n); 
int k = n / 2;


int ** A11 = iniciaMatriz (k); 
int ** A12 = iniciaMatriz (k); 
int ** A21 = iniciaMatriz (k); 
int ** A22 = iniciaMatriz (k); 
int ** B11 = iniciaMatriz (k); 
int ** B12 = iniciaMatriz (k); 
int ** B21 = iniciaMatriz (k); 
int ** B22 = iniciaMatriz (k);
for (int i = 0; i <k; i ++) 
    for (int j = 0; j <k; j ++) { 
        A11 [i] [j] = A [i] [j]; 
        A12 [i] [j] = A [i] [k + j]; 
        A21 [i] [j] = A [k + i] [j]; 
        A22 [i] [j] = A [k + i] [k + j]; 
        B11 [i] [j] = B [i] [j]; 
        B12 [i] [j] = B [i] [k + j]; 
        B21 [i] [j] = B [k + i] [j]; 
        B22 [i] [j] = B [k + i] [k + j]; 
    }


int ** P1 = Strassen  (A11, subtrai (B12, B22, k), k); 
int ** P2 = Strassen  (adiciona (A11, A12, k), B22, k); 
int ** P3 = Strassen  (adiciona (A21, A22, k), B11, k); 
int ** P4 = Strassen  (A22, subtrai (B21, B11, k), k); 
int ** P5 = Strassen  (adiciona (A11, A22, k), adiciona (B11, B22, k), k); 
int ** P6 = Strassen  (subtrai (A12, A22, k), adiciona (B21, B22, k), k); 
int ** P7 = Strassen  (subtrai (A11, A21, k), adiciona (B11, B12, k), k);

int ** C11 = subtrai (adiciona (adiciona (P5, P4, k), P6, k), P2, k); 
int ** C12 = adiciona (P1, P2, k); 
int ** C21 = adiciona (P3, P4, k); 
int ** C22 = subtrai (subtrai (adiciona (P5, P1, k), P3, k), P7, k);


 for(int i = 0; i <k; i ++) 
    for (int j = 0; j <k; j ++) { 
        C [i] [j] = C11 [i] [j]; 
        C [i] [j + k] = C12 [i] [j]; 
        C [k + i] [j] = C21 [i] [j]; 
        C [k + i] [k + j] = C22 [i] [j]; 
    }

  for(int i=0; i<k; i++) {

    free(A11[i]);
    free(A12[i]);
    free(A21[i]);
    free(A22[i]);
   	free(B11[i]);
    free(B12[i]);
    free(B21[i]);
    free(B22[i]);
    free(P1[i]);
    free(P2[i]);
    free(P3[i]);
    free(P4[i]);
    free(P5[i]);
    free(P6[i]);
    free(P7[i]);
    free(C11[i]);
    free(C12[i]);
    free(C21[i]);
    free(C22[i]);
    }
        
    free(A11);
    free(A12);
    free(A21);
    free(A22);
   	free(B11);
    free(B12);
    free(B21);
    free(B22);
    free(P1);
    free(P2);
    free(P3);
    free(P4);
    free(P5);
    free(P6);
    free(P7);
    free(C11);
    free(C12);
    free(C21);
    free(C22);

return C;

}

int main(int argc, char *argv[])
{
  int var = atoi(argv[1]);
  
  double potencia = pow(2, (double)(var)); 

  int parametro = potencia;
  printf("\n- - - - - - - - - - - - - - - - - -");
  printf("\nMatriz de %dx%d",parametro,parametro);
  printf("\n- - - - - - - - - - - - - - - - - -");

  printf("\nCom %d de números aleatórios dentro dela",parametro*parametro);


  printf("\n- - - - - - - - - - - - - - - - - -");
  printf("\n MATRIZ COMUM");

  printf("\n- - - - - - - - - - - - - - - - - -");

  srand(time(NULL));

  int **firstMatrix;
  int **secondMatrix;
  int **finalMatrix;
  int some;
  int p1,p2;


    firstMatrix = (float**)malloc(sizeof(float*) * parametro);
    secondMatrix = (float**)malloc(sizeof(float*) * parametro);
    finalMatrix = (float**)malloc(sizeof(float*) * parametro);


    for (int i=0; i<parametro; i++){
        firstMatrix[i] = (float*)malloc(sizeof(float) * parametro);
        secondMatrix[i] = (float*)malloc(sizeof(float) * parametro);
        finalMatrix[i] = (float*)malloc(sizeof(float) * parametro);
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
            int mudaSinal = rand() % 2 +1;
      if(mudaSinal == 1){
        firstMatrix[i][j] = (rand() % 1000)*-1;
      }else{
        firstMatrix[i][j] = rand() % 1000;

      }
    }
    
  }

  for (int i = 0; i < parametro; i++){
    for (int j = 0; j < parametro; j++){
      int mudaSinal = rand() % 2 +1;
      if(mudaSinal == 1){
        secondMatrix[i][j] = (rand() % 1000)*-1;
      }else{
        secondMatrix[i][j] = rand() % 1000;

      }
    }  
  }

     clock_t t; 
    t = clock(); 
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

    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("\nA matriz normal demorou %f segundos \n", time_taken); 
  printf("\n- - - - - - - - - - - - - - - - - -");


/*     free(*firstMatrix);
    free(*secondMatrix);
    p1 = firstMatrix;
    p2 = secondMatrix;
    p1 = NULL;
    p2 = NULL; */
  printf("\n");

  for (int y = 0; y < parametro; y++){
    for (int x = 0; x < parametro; x++){
      printf("%d ", finalMatrix[y][x]);
    }  
    printf("\n");
  }

  printf("\n- - - - - - - - - - - - - - - - - -");
  printf("\n MATRIZ DE STRASSEN");

  printf("\n- - - - - - - - - - - - - - - - - -");

     clock_t b; 
    b = clock(); 
  int **C= Strassen (firstMatrix,secondMatrix,potencia);

      b = clock() - b; 
    double tempo = ((double)b)/CLOCKS_PER_SEC; // in seconds 
  
    printf("\nA matriz de Strassen demorou %f segundos \n", tempo); 
  printf("\n- - - - - - - - - - - - - - - - - -");

    mostra(C,potencia);

  
  
  return 0;
}
