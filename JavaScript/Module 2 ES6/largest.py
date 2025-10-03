import math, sys

n = int(input())
lst = list(map(int, input().split()))

max_value = -sys.maxsize - 1

for i in range(n):
    if lst[i] >= max_value:
        max_value = lst[i]

print("The largest Number is : ", max_value)
