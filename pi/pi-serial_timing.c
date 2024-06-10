/*
 * numerical integration example - serial code to computer pi
 *
 * compute pi by approximating the area under the curve f(x) = 4 / (1 + x*x)
 * between 0 and 1.
 * using OpenMP timing calls
 *
 */
#include <stdio.h>
#include <omp.h>
#define NBIN 10000

int main() {
	int i; 
	double step,x,sum=0.0,pi;
	double start, last;

	step = 1.0/NBIN;

        start=omp_get_wtime();
 
	for (i=0; i<NBIN; i++) {
		x = (i+0.5)*step;
		sum += 4.0/(1.0+x*x);
	}
	pi = sum*step;
        last =omp_get_wtime();

	printf("PI = %f\n",pi);

	printf("timing = %f\n",last-start);
}
