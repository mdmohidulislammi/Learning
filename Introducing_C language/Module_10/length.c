#include<stdio.h>
#include<string.h>
int main()
{
    char ar[100];
    scanf("%s",ar);
  /*  int len=strlen(ar);
    printf("%d",len);*/

   int count=0;
    for(int i=0;ar[i]!='\\';i++)
    {
        count++;
    }
    printf("%d\n",count);
    return 0;
}