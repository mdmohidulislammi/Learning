#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[50];
    scanf("%s %s",a,b);
       int i=strlen(a);
    for(int j=0;j<=strlen(b);j++)
    {
        a[i]=b[j];
        i++;
        
    }
    
    printf("%s",a);
    return 0;
}