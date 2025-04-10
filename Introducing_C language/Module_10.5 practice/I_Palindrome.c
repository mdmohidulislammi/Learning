#include<stdio.h>
#include<string.h>
int main()
{
    char a[1001],s[1001];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        a[i]=s[i];
        a[strlen(s)]='\0';       
    }     
    int j=strlen(a)-1,i=0;
    while(i<j)
    {
        char tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
        i++;
        j--;
    }
    int b=strcmp(a,s);
    if(b==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}