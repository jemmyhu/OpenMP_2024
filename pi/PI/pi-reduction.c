/*
 * numerical integration example -- PI 
 * parallel version using OpenMP
 * 
 * -- illustrate reduction clause --* 
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>		/* OpenMP header file */
#define NUM_STEPS 10000

/* main program */
int main(int argc, char *argv[]) {

    int i;
    double x, pi;
    double sum = 0.0;
    double step = 1.0/(double) NUM_STEPS;
    int nthreads;

    /* do computation -- using all available threads */
    #pragma omp parallel
    {
        #pragma omp master
        {
            nthreads = omp_get_num_threads();
        }
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

    /* print results */
    printf("parallel program results with %d threads:\n", nthreads);
    printf("pi = %g  (%17.15f)\n",pi, pi);

    return EXIT_SUCCESS;
}

