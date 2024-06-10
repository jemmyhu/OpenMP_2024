/*****************************************************************************
* FILE: ser_mm_hu.c
* DESCRIPTION:  
*   Matrix Multiply - C Version
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define NRA 40                 /* number of rows in matrix A */
#define NCA 20                 /* number of columns in matrix A */
#define NCB 10                  /* number of columns in matrix B */

int main (int argc, char *argv[]) 
{
int i,j,k;
double	a[NRA][NCA];           /* matrix A to be multiplied */
double  b[NCA][NCB];           /* matrix B to be multiplied */
double  c[NRA][NCB];           /* result matrix C */

  /*  printf("Initializing matrices...\n"); */
  /*** Initialize matrices ***/
  for (i=0; i<NRA; i++)
    for (j=0; j<NCA; j++)
      a[i][j]= i+j;
  for (i=0; i<NCA; i++)
    for (j=0; j<NCB; j++)
      b[i][j]= i*j;
  for (i=0; i<NRA; i++)
    for (j=0; j<NCB; j++)
      c[i][j]= 0;

  /*** Do matrix multiply sharing iterations on outer loop ***/
  for (i=0; i<NRA; i++)    
    {
    for(j=0; j<NCB; j++)       
      for (k=0; k<NCA; k++)
        c[i][j] += a[i][k] * b[k][j];
    }


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

