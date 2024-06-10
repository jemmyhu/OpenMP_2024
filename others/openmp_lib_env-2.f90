! demo the default system setting (No. of thread, dynamic, nested)
! try to change the default settings
program scope
    use omp_lib
    implicit none
    integer :: nthreads
    logical :: dynamics, nnested
    integer :: myid
    write(*,*) "start"
        nthreads = omp_get_num_threads()
        dynamics = omp_get_dynamic()
        nnested = omp_get_nested()
        write(*,*) "nthreads, dynamics, nnested : ", nthreads, dynamics, nnested
    write(*,*) "before"
    !$omp parallel private(myid)
        !$omp master 
        nthreads = omp_get_num_threads()
        dynamics = omp_get_dynamic()
        nnested = omp_get_nested()
        write(*,*) "nthreads, dynamics, nnested : ", nthreads, dynamics, nnested
        !$omp end master 
        myid = omp_get_thread_num()
        write(*,*) "myid : ", myid
    !$omp end parallel
    write(*,*) "after"

    write(*,*) "changes before"
    call omp_set_dynamic(.TRUE.)
    call omp_set_nested(.TRUE.)
    !$omp parallel private(myid)
        !$omp master 
        nthreads = omp_get_num_threads()
        dynamics = omp_get_dynamic()
        nnested = omp_get_nested()
        write(*,*) "nthreads, dynamics, nnested : ", nthreads, dynamics, nnested
        !$omp end master 
        myid = omp_get_thread_num()
        write(*,*) "myid : ", myid
    !$omp end parallel
    write(*,*) "after"
end program

