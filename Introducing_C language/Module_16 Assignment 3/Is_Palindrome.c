#include<stdio.h>
#include<string.h>
int is_palindrome(char*s)
{
    char a[1001];
    for(int i=0;i<=strlen(s);i++)
    {
        a[i]=s[i];
    }
    int j=strlen(a)-1;
    for(int i=0;i<j;i++)
    {
        char t=a[i];
        a[i]=a[j];
        a[j]=t;
        j--;
    }
    int p=strcmp(a,s);
    if(p==0)
    {
        p=1;
    }
    else
    {
        p=0;
    }
    return p;
}
int main()
{
    char s[1001];
    scanf("%s",s);
    int p=is_palindrome(s);
    if(p==1)
    {
        printf("Palindrome\n");
    }
    else 
   {
    printf("Not Palindrome\n");
   }
    return 0;
}