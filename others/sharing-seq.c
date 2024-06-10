// simple code to demo data sharin
// add array element

#include <stdio.h>
#define SIZE 500


int main ()
{

  float A[SIZE], total;
  int i, j;

  /* Initializations */
  total = 0.0;
  for (i=0; i < SIZE; i++)
    A[i] = i;

  for (i=0; i < SIZE; i++)
    total = total + A[i];

  printf("Running total= %.2f\n",total);
  
  return 0;

}
