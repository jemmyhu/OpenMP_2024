/*
 * compute pi by approximating the area under the curve f(x) = 4 / (1 + x*x)
 * between 0 and 1.
 *
 * parallel version using OpenMP - non critical, wrong result
 */

#include <stdio.h>
#include <omp.h>
#define NBIN 100000
#define MAX_THREADS 4

int main() {
	double step,sum=0.0,pi;
	step = 1.0/NBIN;

#pragma omp parallel
{
	int nthreads,tid,i;
	double x;
	nthreads = omp_get_num_threads();
	tid = omp_get_thread_num();
	for (i=tid; i<NBIN; i+=nthreads) {
		x = (i+0.5)*step;
		sum += 4.0/(1.0+x*x);
	}
}
pi=sum*step;
printf("PI = %f\n",pi);
}
