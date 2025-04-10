#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],b[1000];
    scanf("%s %s",a,b);
    int al=strlen(a);
    int bl=strlen(b);
    printf("%d %d\n%s %s",al,bl,a,b);
    return 0;
}