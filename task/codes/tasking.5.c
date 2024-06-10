/*
* @@name:	tasking.5
* @@type:	C
* @@compilable:	yes
* @@linkable:	no
* @@expect:	success
* @@version:	omp_3.0
*/
#include <stdio.h>
#include <omp.h>

//#define LARGE_NUMBER 10000000
#define LARGE_NUMBER 100
double item[LARGE_NUMBER];
extern void process(double);

int main()
{
  int tid;
  #pragma omp parallel
  {
    tid = omp_get_thread_num();
    #pragma omp single
    {
      int i;
      for (i=0; i<LARGE_NUMBER; i++)
        #pragma omp task    // i is firstprivate, item is shared
	printf("thread %d did index %d\n",tid,i);
                 // process(item[i]);
    }
  }
}
