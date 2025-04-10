num1, num2= map(int, input().split())
numbers=[]
lucky=False
correct=False
for num in range(num1, num2+1):
    num_str=str(num)
    string=""
    for s in num_str:
        if(s == '4' or s=='7'):
            lucky=True
            string+=s
        elif (s!='4' and s!='7'):
            string=""
            lucky=False
            break
    if lucky==True:
        numbers.append(num)
        correct=True
        lucky=False
if correct==False and lucky==False:
    print('-1')
else:
    for n in numbers:
        print(n, end=' ')
        