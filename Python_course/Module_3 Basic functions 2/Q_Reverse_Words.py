string1=str(input())
string2=""
string3=""
for char in string1:
    if char!=" ":
        string2+=char
        # print(char)
    elif char==" ":
        string3=string2[::-1]
        print(string3, end=' ')
        string2=""
        # print(char)
print(string2[::-1])