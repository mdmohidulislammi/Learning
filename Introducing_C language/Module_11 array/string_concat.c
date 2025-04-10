#include<stdio.h>
#include<string.h>
int main()
{
    char a[200],b[100];
    int i,k;
    scanf("%s %s",a,b);
    strcat(a,b);
     /* i=strlen(a);
    for(k=0;k<=strlen(b);k++)
    {
        a[i]=b[k];
        i++;
    }*/
    printf("%s",a);
    return 0;
}