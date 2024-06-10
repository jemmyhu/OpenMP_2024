/*****************************************************************************
* DESCRIPTION:  
*   OpenMp Example - Matrix Multiply - C Version
*   Demonstrates a matrix multiply using OpenMP. 
*   size N
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 12          

int main (int argc, char *argv[]) 
{
int	tid, nthreads, i, j, k;
double	a[N][N],           /* matrix a */ 
	b[N][N],           /* matrix b */
	c[N][N];           /* result matrix C */

double start_time, end_time;  /* timing for performance measure when N is big enough*/

   /* record start time */
    start_time = omp_get_wtime();

/*** Spawn a parallel region explicitly scoping all variables ***/
#pragma omp parallel shared(a,b,c,nthreads) private(tid,i,j,k)
  {
  tid = omp_get_thread_num();
  if (tid == 0)
    {
    nthreads = omp_get_num_threads();
  /*  printf("Starting matrix multiple example with %d threads\n",nthreads); */
  /*  printf("Initializing matrices...\n"); */
    }

  #pragma omp for 
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
    {
      a[i][j]= i+j;
      b[i][j]= i*j;
      c[i][j]= 0;
    }
  /*** Do matrix multiply sharing iterations on outer loop ***/
  /*** Display who does which iterations for demonstration purposes ***/
/*  printf("Thread %d starting matrix multiply...\n",tid); */
  #pragma omp for 
  for (i=0; i<N; i++)    
    {
    printf("Thread=%d did row=%d\n",tid,i); 
    for(j=0; j<N; j++)       
      for (k=0; k<N; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
  }   /*** End of parallel region ***/

 /* record end time */
    end_time = omp_get_wtime();

    /* print results */
    printf("parallel program results with %d threads:\n", nthreads);
    printf("time to compute = %g seconds\n", end_time - start_time);

/*** Print results ***/
printf("******************************************************\n");
printf("Result Matrix:\n");
for (i=0; i<N; i++)
  {
  for (j=0; j<N; j++) 
    printf("%6.2f   ", c[i][j]);
  printf("\n"); 
  }
printf("******************************************************\n");
printf ("Done.\n");

}

