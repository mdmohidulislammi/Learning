REAL N,SUM,I
PRINT*, "Enter the value of n : "
READ*, N
SUM =0
   DO 10 I=1,N 
      SUM =SUM + (I**3)
10 CONTINUE
PRINT *, "Here is the summation : ", SUM 
STOP 
END
