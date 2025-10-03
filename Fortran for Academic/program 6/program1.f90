REAL A,B, largest
PRINT *, "Enter two value : "
READ *, A,B
largest=A
IF(B .GT. A) THEN 
largest=B
ENDIF
PRINT*, "The largest number is : ", largest

STOP 
END 
