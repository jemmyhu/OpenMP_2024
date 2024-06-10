program scope
    use omp_lib
    implicit none
    integer :: myid, myid2
    write(*,*) "before"
    !$omp parallel private(myid, myid2)
        myid = omp_get_thread_num()
        myid2 = omp_get_thread_num()
        write(*,*) "myid myid2 : ", myid, myid2
    !$omp end parallel
    write(*,*) "after"
end program

