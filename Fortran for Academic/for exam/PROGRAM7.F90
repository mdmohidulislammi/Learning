INTEGER A(2,3),B(3,4),MUL(2,4),SUM
      SUM =0
      PRINT*,'A= '
      DO 10 I=1,2
        READ*,(A(I,J),J=1,3)
 10       CONTINUE

        PRINT*,'B= '
      DO 20 I=1,3
        READ*,(B(I,J),J=1,4)
 20       CONTINUE
       DO 50 I=1,2
         DO 60 J=1,4
           DO 70 K=1,3         
             SUM=SUM+A(I,K)*B(K,J)             
 70        CONTINUE
        MUL(I,J)=SUM
        SUM=0
 60     CONTINUE
 50     CONTINUE

      PRINT*,'MUL='
      DO 100 I=1,2
        PRINT*,(MUL(I,J),J=1,4)
 100       CONTINUE

      STOP
      END