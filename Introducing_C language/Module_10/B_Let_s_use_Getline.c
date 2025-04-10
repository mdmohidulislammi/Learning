#include<stdio.h>
#include<string.h>
int main()
{
    char ar[100000];
    int i;
    fgets(ar,sizeof(ar),stdin);
    for(i=0;ar[i]!='\\';i++)
    {
        printf("%c",ar[i]);
    }
    return 0;
}