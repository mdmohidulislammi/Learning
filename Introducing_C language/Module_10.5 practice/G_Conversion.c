#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            printf("%c",s[i]+32);
        }
       else if(s[i]>='a' && s[i]<='z')
        {
            printf("%c",s[i]-32);
        }
        else if(s[i]==',')
        {
            printf(" ");
        }
    }
    return 0;
}