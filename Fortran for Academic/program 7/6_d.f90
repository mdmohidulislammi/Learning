REAL A,B,C,D,E
PRINT*, "Enter five numbers : "
READ*, A,B,C,D, E 
IF (A .GT. B .AND. A .GT. C .OR. A .LT. D .AND. A .NE. E) THEN
PRINT *, "OOPS"
ENDIF
STOP 
END