/* demo serial-parallel pattern model
 * serial-parallel-serial
*/
#include <omp.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
  printf("before \n");
  #pragma omp parallel
    printf("Hello World \n");
  printf("after \n");
  return 0;
}
