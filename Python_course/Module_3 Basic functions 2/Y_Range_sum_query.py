n, t= map(int, input().split())
lst=list(map(int, input().split()))
lst_pre_sum=list()
lst_pre_sum.append(0)
lst_pre_sum.append(lst[0])
for i, value in enumerate(lst):
    if i==0: continue
    else:
        lst_pre_sum.append(int(lst_pre_sum[i] ) + int(lst[i]))

for i in range (0,t):
    a,b= map(int, input().split())
    # print(a,b)
    print(int(lst_pre_sum[b])-int(lst_pre_sum[a-1]))
print(lst_pre_sum)