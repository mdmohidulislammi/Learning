REAL A,B,I,SUM
I=1
100 IF (I .GT. 10) STOP 
 PRINT*, "Enter two value : "
 READ *, A,B
 SUM=A+B
 PRINT*, A," + ",B," = ",SUM
 I=I+1
 GO TO 100
END