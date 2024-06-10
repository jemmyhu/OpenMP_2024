// loop examples

#include <stdio.h>
#define N 10000
int main()
{
   long d1=0;
   double a[N], b[N], c[N], d2=0.0;
	   
   for (int i=0;i<N;i++)
       d1+=i*(N+1-i);
        
   for (int i=0; i<N;i++) {
         a[i]=i;
         b[i]=N+1-i;
   }
		    
   for (int i=0; i<N; i++)
       d2+=a[i]*b[i];

   printf("result1 = %ld\nresult2 = %.2lf\n", d1, d2);
}

