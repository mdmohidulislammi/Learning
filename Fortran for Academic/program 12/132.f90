
  INTEGER square, cube, i 
  INTEGER(kind=8) :: quad

  PRINT *, "  NUMBER      SQUARE       CUBE            QUAD"
  
  DO i = 101, 125
     square = i**2
     cube = i**3
     quad = i**4
     PRINT '(I8, I12, I14, I18)', i, square, cube, quad
  END DO
STOP
END 