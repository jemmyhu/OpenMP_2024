! Simple code to demo OpenMP parallel region only construct
! manually control the workload by case() in c

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

  !$omp parallel
     select case (omp_get_thread_num())
        case (0)
          do i = 1, NX
             ri = real(i)
             x(i) = atan(ri)/ri
          end do
       case (1)
          do j = 1, NY
             rj = real(j)
             y(j) = cos(rj)/rj
          end do
       case (2)
          do k = 1, NZ
             rk = real(k)
             z(k) = log10(rk)/rk
          end do
      end select
  !$omp end parallel

  write(*,*) "end"

end program
