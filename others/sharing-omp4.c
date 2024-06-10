// simple code to demo data sharin
// more specific, for data sum, OpenMP reduction clause works better(faster) 
// than 'atomic' and 'critical'

#include <omp.h>
#include <stdio.h>
#define SIZE 500


int main ()
{

  float A[SIZE], total;
  int i, j, tid;

  /* Initializations */
  total = 0.0;
  #pragma omp parallel shared(A,total) private(tid,i)
  {
  #pragma omp for
  for (i=0; i < SIZE; i++)
    A[i] = i;

  #pragma omp for reduction(+:total) 
  for (i=0; i < SIZE; i++)
  {
    total = total + A[i];
  }


  }

  printf("Running total= %.2f\n",total);
  
  return 0;

}
