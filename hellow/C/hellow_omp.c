/* hellow-omp.c */

#include <omp.h>  // OpenMP header file
#include <stdio.h>

int main (int argc, char *argv[]) {
  int id, nthreads;
  #pragma omp parallel private(id) //paralle region directive + data scope
  {
    id = omp_get_thread_num();     //runtime library routine calls
    nthreads = omp_get_num_threads();
    printf("Hello World from thread %d\n", id);
    #pragma omp barrier            //synchronization
    if ( id == 0 ) {
      printf("There are %d threads\n",nthreads);
    }
  }
}
