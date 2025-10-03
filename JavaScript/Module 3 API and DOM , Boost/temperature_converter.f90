! PROGRAM TempConverter
  IMPLICIT NONE
  INTEGER :: Option
  REAL :: Celc_T, Fahr_T

  PRINT *, "!! Welcome to our temperature converter program !!"
  PRINT *, "Please choose your option:"
  PRINT *, "1. Celsius to Fahrenheit"
  PRINT *, "2. Fahrenheit to Celsius"
  PRINT *, "3. Exit"

  READ (*,*) Option
 
  IF (Option == 1) THEN
    PRINT*, "!! Welcome to Celsius to Fahrenheit Converter !!"
    PRINT*, "Please enter the temperature in Celsius: "
    READ *, Celc_T
    Fahr_T = ((9.0/5.0) * Celc_T) + 32.0
    PRINT*, "!! Ohh Great !! Your desired result is", Fahr_T, "Degrees Fahrenheit."
    PRINT*, "Thanks for using this program."

  ELSE IF (Option == 2) THEN
    PRINT*, "!! Welcome to Fahrenheit to Celsius Converter !!"
    PRINT*, "Please enter the temperature in Fahrenheit: "
    READ *, Fahr_T
    Celc_T = (5.0/9.0) * (Fahr_T - 32.0)
    PRINT*, "!! Ohh Great !! Your desired result is", Celc_T, "Degrees Celsius."
    PRINT*, "Thanks for using this program."

  ELSE
    PRINT*, "Exiting the program. Have a great day!"
  END IF

  STOP
END PROGRAM
