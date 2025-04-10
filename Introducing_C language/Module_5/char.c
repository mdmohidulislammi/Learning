#include<stdio.h>
int main()
{
    char ch,ans;
    scanf("%c",&ch);
    if('a'<=ch && ch<='z')
    {
        ans=ch-32;
        printf("%c",ans);
    }
    else
    {
        ans=ch+32;
        printf("%c",ans);
    }
    return 0;
}