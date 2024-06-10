// parallel vs single
#include <stdio.h>
#include <omp.h>

#define T 2
#define N 8

int main() {
    int x1 = 0, x2 = 0;
    #pragma omp parallel shared(x1,x2) num_threads(T)
    {
        //int id = omp_get_thread_num();
        #pragma omp taskloop
        for (int i = 0; i < N; ++i) {
	   printf("I am thread no. %d.\n", omp_get_thread_num());
	   //printf("I am thread no. %d.\n", id);
            #pragma omp atomic
            x1++;          // executed T*N times
        }
	#pragma omp taskwait
        printf(" ......\n");

        #pragma omp single
        #pragma omp taskloop
        for (int i = 0; i < N; ++i) {
	   printf("I am thread no. %d.\n", omp_get_thread_num());
	   //printf("I am thread no. %d.\n", id);
            #pragma omp atomic
            x2++;          // executed N times
        }
    }

    printf("x1 = %d, x2 = %d\n", x1, x2);
}
