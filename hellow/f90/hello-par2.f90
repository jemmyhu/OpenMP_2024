program hello
  write(*,*) "before"
  !$omp parallel
     write(*,*) "Hello, parallel world!"
  !$omp end parallel
  write(*,*) "after"
end program
