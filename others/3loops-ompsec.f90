! Simple code to demo OpenMP 'section' worksharing construct

program compute
  use omp_lib
  implicit none
  integer, parameter :: NX = 1000
  integer, parameter :: NY = 2000
  integer, parameter :: NZ = 3000
  real :: x(NX)
  real :: y(NY)
  real :: z(NZ)
  integer :: i, j, k
  real :: ri, rj, rk

  write(*,*) "start"

  !$omp parallel sections
     !$omp section
         do i = 1, NX
            ri = real(i)
            x(i) = atan(ri)/ri
         end do
     !$omp section
         do j = 1, NY
            rj = real(j)
            y(j) = cos(rj)/rj
         end do
     !$omp section
         do k = 1, NZ
            rk = real(k)
            z(k) = log10(rk)/rk
         end do
  !$omp end parallel sections

  write(*,*) "end"

end program
