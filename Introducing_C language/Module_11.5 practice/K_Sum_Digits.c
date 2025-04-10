#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    char a[n];
    scanf("%s",a);
    for(i=0;i<strlen(a);i++)
    {
         sum=sum+a[i]-'0';
    }
    printf("%d",sum);
    return 0;
}