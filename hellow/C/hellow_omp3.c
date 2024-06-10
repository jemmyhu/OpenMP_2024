/* call OpenMP Library routine to get thread id 
* and total thread number (nthreads)
* add to hellow-omp2.c
*/
#include <omp.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
  int id, nthreads;
  printf("before\n");
  #pragma omp parallel private(id)
  {
    id = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    printf("Hello World from thread %d\n", id);
    printf("There are %d threads\n",nthreads);
  }
  printf("after \n");
}
