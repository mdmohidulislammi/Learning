
#define
def double_it(num):
 result =num*2
 print(result)
double_it(8)
def sum(num1, num2):
 result=num1+num2
 return result
total =sum(44,39)
print (total)

def sum(num1, num2, num3=0):
 return num1+num2+num3
print(sum(1,3,6))

def all_num(*numbers):
 print(numbers)
 sum=0
 for num in numbers:
  sum=sum+num
 return sum
print(all_num(3,5,10,100))
