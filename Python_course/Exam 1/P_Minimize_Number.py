import math
n = int(input())
lst = list(map(int, input().split()))

cnt = int(0)
for i, element in enumerate(lst):
    if element % 2 != 0:
        break
    else:
        lst.append(element/2)
        cnt+=1
print(math.floor(cnt/n))
