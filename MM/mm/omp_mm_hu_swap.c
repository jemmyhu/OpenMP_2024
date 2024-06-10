/*****************************************************************************
* DESCRIPTION:  
*   OpenMp Example - Matrix Multiply - C Version
*   Demonstrates a matrix multiply using OpenMP. Threads share row iterations
*   with default runtime static schedule 
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NRA 40                 /* number of rows in matrix A */
#define NCA 20                 /* number of columns in matrix A */
#define NCB 10                 /* number of columns in matrix B */

int main (int argc, char *argv[]) 
{
int	tid, nthreads, i, j, k;
double	a[NRA][NCA],           /* matrix A to be multiplied */
	b[NCA][NCB],           /* matrix B to be multiplied */
	c[NRA][NCB];           /* result matrix C */

double start_time, end_time;

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
  for (i=0; i<NRA; i++)
    for (j=0; j<NCA; j++)
      a[i][j]= i+j;
  #pragma omp for 
  for (i=0; i<NCA; i++)
    for (j=0; j<NCB; j++)
      b[i][j]= i*j;
  #pragma omp for
  for (i=0; i<NRA; i++)
    for (j=0; j<NCB; j++)
      c[i][j]= 0;

  /*** Do matrix multiply sharing iterations on outer loop ***/
  //swapping the loop iterating over i and the one iterating over k (that does not work with collapse(2)) is several times faster on most systems due to more contiguous memory accesses
 //The loop order IKJ will vectorize better
  /*** Display who does which iterations for demonstration purposes ***/
/*  printf("Thread %d starting matrix multiply...\n",tid); */
  #pragma omp for 
  for (i=0; i<NRA; i++)    
    {
    printf("Thread=%d did row=%d\n",tid,i); 
    for (k=0; k<NCA; k++)
      for(j=0; j<NCB; j++)       
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
for (i=0; i<NRA; i++)
  {
  for (j=0; j<NCB; j++) 
    printf("%6.2f   ", c[i][j]);
  printf("\n"); 
  }
printf("******************************************************\n");
printf ("Done.\n");

}

