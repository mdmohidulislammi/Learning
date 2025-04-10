#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char s[100001];
    for(int i=0;i<n;i++)
    {
        int cl=0,sl=0,d=0;
        scanf("%s",s);
        for(int j=0;j<strlen(s);j++)
        {
            if('A'<=s[j] && s[j]<='Z')
            {
                cl++;
            }
            else if('a'<=s[j] && s[j]<='z')
            {
                sl++;
            }
            else if('0'<=s[j] && s[j]<='9')
            {
                d++;
            }
            
        }
        printf("%d %d %d\n",cl,sl,d);
    }
}