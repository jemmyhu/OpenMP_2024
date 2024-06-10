// add clauses to control
// grainsize() sets the number of iterations assigned to each tasks  
// num_tasks sets the number of tasks generated.

#include <stdio.h>
#include <omp.h>

int main() {
  // Use 4 threads when creating OpenMP parallel regions
  //      omp_set_num_threads(4);

    #pragma omp parallel
    #pragma omp single nowait
    {
        #pragma omp taskloop grainsize(2)
        for (int i = 0; i < 12; i++) {
            printf("I am thread no. %d.\n", omp_get_thread_num());
        }
    }
    return 0;
}
