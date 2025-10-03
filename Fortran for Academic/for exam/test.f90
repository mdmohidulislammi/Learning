        dimension score(1:100), test(-2:6)
        real score, test
        integer a
        a=1
10      if (a .gt. 5) goto 20
        print *, "Please input value : "
        read *, score(a)
        a=a+1
        goto 10

20      a=1
30      if (a .gt. 5) goto 99
        print *, score(a)
        a=a+1
        goto 30
99      stop
        end