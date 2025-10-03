
REAL  A, B, C, D, ROOT1, ROOT2

PRINT *, "ENTER THREE VALUES (A, B, C):"
READ *, A, B, C

IF (A) 2,3,4
2 CONTINUE
    D = B*B - 4*A*C
    IF (D) 10, 20, 30
3  PRINT *, "A cannot be zero in a quadratic equation."
   ENDIF

4 CONTINUE
    D = B*B - 4*A*C
    IF (D) 10, 20, 30

10  CONTINUE
    PRINT *, "Complex roots. Not valid for this program."
    GOTO 100

20  CONTINUE
    ROOT1 = -B / (2*A)
    PRINT *, "THE ROOT IS: ", ROOT1
    GOTO 100

30  CONTINUE
    ROOT1 = (-B + SQRT(D)) / (2*A)
    ROOT2 = (-B - SQRT(D)) / (2*A)
    PRINT *, "THE ROOTS ARE: ", ROOT1, ROOT2

100 CONTINUE
ENDIF

STOP
END PROGRAM 
