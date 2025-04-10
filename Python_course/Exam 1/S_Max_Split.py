string=str(input())
string1=""
lst=list()
count_str=int(0)
countL=int(0)
countR=int(0)
for i, char in enumerate(string):
    if string[i]=='L': countL+=1
    else: countR+=1
    string1+=char
    if countL==countR:
        countL=0
        countR=0
        lst.append(string1)
        string1=""
        count_str+=1
print(count_str)
for word in lst:
    print(word)