// use taskloop instead of task from tasking2.c

#include <stdio.h>
#include <omp.h>

int main() {
  // Use 4 threads when creating OpenMP parallel regions
   //     omp_set_num_threads(4);

    #pragma omp parallel
    #pragma omp single nowait
    {
        #pragma omp taskloop
        for (int i = 0; i < 12; i++) {
            //#pragma omp task
            printf("I am thread no. %d.\n", omp_get_thread_num());
        }
    }
    return 0;
}
