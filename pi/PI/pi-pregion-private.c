/*
 * compute pi by approximating the area under the curve f(x) = 4 / (1 + x*x)
 * between 0 and 1.
 *
 * parallel version using OpenMP 
 * - parallel region 
 *     - array solution to 'sum'
 *     - need to manually distribute the workload 
 */
// tid is a global variable, need to scope it to be private
#include <stdio.h>
#include <omp.h>

#define NBIN 10000
#define MAX_THREADS 4

int main() {
	int nthreads,tid;
	double step,sum[MAX_THREADS]={0.0},pi=0.0;

	step = 1.0/NBIN;

   #pragma omp parallel private(tid) 
   {
	int i;
	double x;
	nthreads = omp_get_num_threads();
	tid = omp_get_thread_num();
	for (i=tid; i<NBIN; i+=nthreads) {
		x = (i+0.5)*step;
		sum[tid] += 4.0/(1.0+x*x);
	}
   }
   for(tid=0; tid<nthreads; tid++) 
	pi += sum[tid]*step;
   printf("PI = %f\n",pi);
}
