// simple code to demo data sharin
// incorrect due to datat racei
// give different value of 'total' for each run

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

  #pragma omp for 
  for (i=0; i < SIZE; i++)
    total = total + A[i];
  }

  printf("Running total= %.2f\n",total);
  
  return 0;

}
