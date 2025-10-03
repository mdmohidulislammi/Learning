INTEGER X(2,2)
READ*, X
    DO 10 I = 1,2
       DO 20 J=1,2
       PRINT*, I, J , ": ", X(I, J)
20     CONTINUE
10  CONTINUE
STOP 
END 