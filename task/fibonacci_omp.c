// example C code to calculate Fibonacci number for a given interger N
// using OpenMP task constructs

#include <stdio.h>
#include <omp.h>
int fib(int n)
{
  int i, j;
  if (n<2)
    return n;
  else
    {
       #pragma omp task shared(i) firstprivate(n)
       i=fib(n-1);

       #pragma omp task shared(j) firstprivate(n)
       j=fib(n-2);

       #pragma omp taskwait
       return i+j;
    }
}

int main()
{
  int i, id, nthreads;
  int n = 12;

  #pragma omp parallel private(id)
  {
    id = omp_get_thread_num();  
    #pragma omp for
       for (i=0; i<n; i++)
       {
          printf ("fib(%d) = %d\n from thread %d\n", i, fib(i), id);
       }

    #pragma omp single
    {
       nthreads = omp_get_num_threads();  
       printf("There are %d threads\n",nthreads);
       printf ("fib(%d) = %d\n", n, fib(n));
    }
  }
}
