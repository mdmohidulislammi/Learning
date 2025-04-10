#include<stdio.h>
int main()
{
    int N,i;
    scanf("%d", &N);
    for(i=1;(i <= N) && (21 <= N <= 10000);i++)
    { if((i%3 == 0) && (i%7 == 0))
     {  
        printf("%d\n",i);
        }
    }
    return 0;
}