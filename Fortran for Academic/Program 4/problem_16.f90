REAL X1,X2,X3,AVERAGE, SD, RP1,RP2,RP3
PRINT*, "Enter three numbers : "
READ*, X1,X2,X3
AVERAGE= (X1+X2+X3)/3
SD= SQRT((X1**2 + X2**2 +X3**2 -3*AVERAGE**2)/3)
RP1=(X1/(X1+X2+X3))*100
RP2=(X2/(X1+X2+X3))*100
RP3=(X3/(X1+X2+X3))*100
PRINT*, "The average is : ",AVERAGE
PRINT*, "The standerd deviation is : ",SD
PRINT*, "The Relative Percentage of X1 is :", RP1
PRINT*, "The Relative Percentage of X2 is :", RP2
PRINT*, "The Relative Percentage of X3 is :", RP3
STOP 
END