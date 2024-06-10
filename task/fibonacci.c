// example C code to calculate Fibonacci number for a given interger N

#include <stdio.h>
int fib(int n)
{
  int i, j;
  if (n<2)
    return n;
  else
    {
       i=fib(n-1);

       j=fib(n-2);

       return i+j;
    }
}

int main()
{
  int i;
  int n = 12;
 
  for (i=0; i<n; i++)
  {
    printf ("fib(%d) = %d\n", i, fib(i));
  }

  printf ("fib(%d) = %d\n", n, fib(n));

  return 0;
}
