#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000001],p[1000001];
    int cnt=0;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        p[i]=s[i];
    }
    int j=strlen(s)-1;
    for(int i=0;i<j;i++)
    {
        char t=p[i];
        p[i]=p[j];
        p[j]=t;
        j--;
    }
    for(int i=0;i<strlen(s);i++)
    {
        if(p[i]=='0')
        cnt++;
        if(p[i]!='0')
        break;
    }
    int z=strcmp(p,s);
    for(int i=cnt;i<strlen(s);i++)
    {
       printf("%c",p[i]);
    }
    if(z==0)
    {
        printf("\nYES");
    }
    else 
    {
        printf("\nNO");
    }
    return 0;
}