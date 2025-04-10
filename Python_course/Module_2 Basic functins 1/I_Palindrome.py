number=str(input())
rever=number[::-1]
int_re=int(rever)
int_to_str=str(int_re)
if(number==int_to_str):
    print(int_to_str ,"\nYES")
else:
    print(int_to_str, "\nNO")