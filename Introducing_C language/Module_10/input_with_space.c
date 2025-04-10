#include<stdio.h>
#include<string.h>
int main()
{
    char ar[100];
   // gets(ar);
   //fgets(ar,18,stdin);
   fgets(ar,sizeof(ar),stdin);
   ar[18]='\0';
    printf("%s",ar);
    return 0;
}