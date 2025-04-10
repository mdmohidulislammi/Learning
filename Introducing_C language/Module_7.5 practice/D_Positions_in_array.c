#include<stdio.h>
int main()
{
    int a,n,i;
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<n;i++)
    {
        if(10>=ar[i])
        {
            printf("A[%d] = %d\n",i,ar[i]);
        }
    }
    return 0;
}