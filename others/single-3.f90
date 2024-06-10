! demo Single directive by print which thread does what
!  call runtime library functions 

PROGRAM single_3
INTEGER NTHREADS, TID, TID2, OMP_GET_NUM_THREADS, OMP_GET_THREAD_NUM

write(*,*) "Start"

!$OMP PARALLEL PRIVATE(TID, i)

!$OMP DO
do i=1,8
TID = OMP_GET_THREAD_NUM()
write(*,*) "thread: ", TID, 'i = ', i
enddo
!$OMP END DO 

!$OMP SINGLE
write(*,*) "SINGLE - begin"
do i=1,8
TID2 = OMP_GET_THREAD_NUM()
PRINT *, 'This is from thread = ', TID2
write(*,*) 'hello',i
enddo
!$OMP END SINGLE

!$OMP END PARALLEL

write(*,*) "End "

END 
