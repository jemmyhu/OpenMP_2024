program hello90
use omp_lib
integer :: id, nthreads
  !$omp parallel private(id)
  id = omp_get_thread_num()
  write (*,*) 'Hello World from thread', id
  !$omp barrier
    nthreads = omp_get_num_threads()
    write (*,*) 'There are', nthreads, 'threads'
  !$omp end parallel
end program
