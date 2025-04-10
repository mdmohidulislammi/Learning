from collections import Counter

n = int(input())
lst = list(map(int, input().split()))
dic = Counter(lst)
# print(dic)
cnt = 0
for number, count in dic.items():
    if number == 0:
        cnt += 1
    elif number > count:
        cnt += count
    elif number < count:
        cnt += (count - number)

print(cnt)
