PROGRAM REDUCTION 
USE omp_lib

        IMPLICIT NONE
        INTEGER tnumber
        INTEGER I,J,K
        I=1
        J=1
        K=1
        PRINT *, "Before Par Region: I=",I," J=", J," K=",K
        PRINT *, ""

!$OMP PARALLEL private(tnumber) REDUCTION(+:I) REDUCTION(*:J) REDUCTION(MAX:K)

        tnumber=OMP_GET_THREAD_NUM()

        I = tnumber
        J = tnumber
        K = tnumber

        PRINT *, "Thread ",tnumber, "         I=",I," J=", J," K=",K

!$OMP END PARALLEL

        PRINT *, ""
        print *, "Operator            +     *    MAX"
        PRINT *, "After Par Region:  I=",I," J=", J," K=",K

END PROGRAM REDUCTION 
