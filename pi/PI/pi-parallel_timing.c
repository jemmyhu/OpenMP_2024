/*
 * compute pi by approximating the area under the curve f(x) = 4 / (1 + x*x)
 * between 0 and 1.
 *
 * parallel version using OpenMP for, timing.
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>		/* OpenMP header file */
#define NUM_STEPS 100000000

/* main program */
int main(int argc, char *argv[]) {

    double start_time, end_time;
    int i;
    double x, pi;
    double sum = 0.0;
    double step = 1.0/(double) NUM_STEPS;
    int nthreads;

    /* record start time */
    start_time = omp_get_wtime();

    /* do computation -- using all available threads */
    #pragma omp parallel
    {
        #pragma omp master
        {
            nthreads = omp_get_num_threads();
        }
        //#pragma omp for private(x) reduction(+:sum) schedule(runtime)
        #pragma omp for private(x) reduction(+:sum)
        for (i=0; i < NUM_STEPS; ++i) {
            x = (i+0.5)*step;
            sum = sum + 4.0/(1.0+x*x);
        }
        #pragma omp master
        {
            pi = step * sum;
        }
    }

    /* record end time */
    end_time = omp_get_wtime();

    /* print results */
    printf("parallel program results with %d threads:\n", nthreads);
    printf("pi = %g  (%17.15f)\n",pi, pi);
    printf("time to compute = %g seconds\n", end_time - start_time);

    return EXIT_SUCCESS;
}

