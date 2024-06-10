/*****************************************************************************
* DESCRIPTION:  
*   Matrix Multiply - C Version
*   size N
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define N 12          

int main (int argc, char *argv[]) 
{
int	i, j, k;
double	a[N][N],           /* matrix a */ 
	b[N][N],           /* matrix b */
	c[N][N];           /* result matrix C */

  /* Initializing matrices... */

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
    {
      a[i][j]= i+j;
      b[i][j]= i*j;
      c[i][j]= 0;
    }

/*  Starting matrix multiply... */
  for (i=0; i<N; i++)    
    for(j=0; j<N; j++)       
      for (k=0; k<N; k++)
        c[i][j] += a[i][k] * b[k][j];

/*** Print results ***/
printf("Result Matrix:\n");
for (i=0; i<N; i++)
  {
  for (j=0; j<N; j++) 
    printf("%6.2f   ", c[i][j]);
  printf("\n"); 
  }
printf ("Done.\n");

}

