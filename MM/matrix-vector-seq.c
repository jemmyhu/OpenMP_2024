/******************************************************************************
* OpenMP Example - Matrix-vector multiplication - C/C++ Version
* DESCRIPTION:
*   This example multiplies all row i elements of matrix A with vector
*   element b(i) and stores the summed products in vector c(i).  A total is
*   maintained for the entire matrix. 
******************************************************************************/

#include <stdio.h>
#define SIZE 10


int main ()
{

float A[SIZE][SIZE], b[SIZE], c[SIZE], total;
int i, j, tid;

/* Initializations */
total = 0.0;
for (i=0; i < SIZE; i++)
  {
  for (j=0; j < SIZE; j++)
    A[i][j] = (j+1) * 1.0;
    b[i] = 1.0 * (i+1);
    c[i] = 0.0;
  }
printf("\nStarting values of matrix A and vector b:\n");
for (i=0; i < SIZE; i++)
  {
  printf("  A[%d]= ",i);
  for (j=0; j < SIZE; j++)
    printf("%.1f ",A[i][j]);
  printf("  b[%d]= %.1f\n",i,b[i]);
  }
printf("\nResults by thread/row:\n");

  for (i=0; i < SIZE; i++)
    {
    for (j=0; j < SIZE; j++)
      c[i] += (A[i][j] * b[i]);

      total = total + c[i];
      printf("  row %d\t c[%d]=%.2f\t",i,i,c[i]);
      printf("Running total= %.2f\n",total);

    }   /* end of parallel i loop */


printf("\nMatrix-vector total - sum of all c[] = %.2f\n\n",total);

}


