n=int(input())
lst=list(map(int, input().split()))
min_val=min(lst)
max_val=max(lst)
new_list=list()
for value in lst:
    if value==min_val:
        new_list.append(max_val)
    elif value==max_val:
        new_list.append(min_val)
    else:
        new_list.append(value)
for val in new_list:
    print(val, end=' ')