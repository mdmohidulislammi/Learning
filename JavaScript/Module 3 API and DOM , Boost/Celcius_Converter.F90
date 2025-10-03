REAL Temp_C ,Temp_F
PRINT*, "Please Enter the temperature in Celcius : "
READ *, Temp_C
Temp_F = ((9.0/5.0)* Temp_C) + 32
PRINT *,"Your result is " ,Temp_F,"Degree Fahrenheit."
STOP
END PROGRAM