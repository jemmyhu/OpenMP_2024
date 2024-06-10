! Laplac equation with iterative method
!   solving the equation on a finite square plate of length L
!   in the x- and y- directions, and the number of points in the
!   x- and y- directions are imax and jmax, respectively.
!   use simplified Dirichlet conditions
!   u(0,y)=0, u(x,0)=0, u(x,L)=0, u(L,y)=umax
!
! Fortran 90 code, OpenMP version
!   (for test purpose, no convergence (tol)
!   Two parallel regions, 3 parallel do worksharing loops
!
!
program lpomp
use omp_lib
integer imax,jmax,im1,im2,jm1,jm2,it,itmax
parameter (imax=2002,jmax=2002)
parameter (im1=imax-1,im2=imax-2,jm1=jmax-1,jm2=jmax-2)
parameter (itmax=1000)
real*8 u(imax,jmax),du(imax,jmax),umax,dumax,tol
parameter (umax=10.0,tol=1.0e-6)
real*8 start_time, end_time, walltime

start_time = OMP_get_wtime()

!$OMP PARALLEL DEFAULT(SHARED) PRIVATE(i,j)

  !$OMP DO
    do j=1,jmax
       do i=1,imax-1
          u(i,j)=0.0
          du(i,j)=0.0
       enddo
       u(imax,j)=umax
    enddo
  !$OMP END DO

 ! ! print value of u
 ! !$OMP MASTER
 !   do j=1,jmax
 !         write(*, '(1X, 100G10.5)') (u(i,j), i=1, imax)
 !   enddo
 ! !$OMP END MASTER

!$OMP END PARALLEL


!$OMP PARALLEL DEFAULT(SHARED) PRIVATE(i,j)

! Main computation loop
  do it=1,itmax
     dumax=0.0
     !$OMP DO REDUCTION (max:dumax)
         do j=2,jm1
            do i=2,im1
               du(i,j)=0.25*(u(i-1,j)+u(i+1,j)+u(i,j-1)+u(i,j+1))-u(i,j)
               dumax=max(dumax,abs(du(i,j)))
            enddo
         enddo
     !$OMP END DO

     !$OMP DO
        do j=2,jm1
           do i=2,im1
              u(i,j)=u(i,j)+du(i,j)
           enddo
        enddo
     !$OMP END DO

  !   ! print value of u
  !   !$OMP MASTER
  !      write(*, '(1x)')
  !      do j=1,jmax
  !         write(*, '(1X, 100G10.5)') (u(i,j), i=1, imax)
  !      enddo
  !      write (*,*) it,dumax
  !   !$OMP END MASTER

  enddo

!  !$OMP MASTER
!     write (*,*) it,dumax
!  !$OMP END MASTER

!$OMP END PARALLEL

end_time = OMP_get_wtime()
walltime = end_time - start_time

write (*,*) it,dumax
write(*, '(1x)')
write(*, '(1X, 50G10.5)') 'Walltime = ', walltime, 'seconds'

stop
end
