program hello
use omp_lib
  write(*,*) "before"
  !$omp parallel
     write(*,*) "Hello, from thread ", omp_get_thread_num()
  !$omp end parallel
  write(*,*) "after"
end program
