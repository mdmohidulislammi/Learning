REAL Temp_C,Temp_F
PRINT*, "Please Enter the temperature in Fahrenheit : "
READ *, Temp_F
Temp_C = (5.0/9.0)* (Temp_F - 32)
PRINT *,"Your result is " ,Temp_C,"Degree Celcius."
STOP
END PROGRAM