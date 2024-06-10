program hello
  !$omp parallel
     write(*,*) "Hello, world!"
  !$omp end parallel
end program
