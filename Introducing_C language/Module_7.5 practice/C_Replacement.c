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
        if(0<ar[i])
        {
            printf("1 ");
        }
        else if(0>ar[i])
        {
            printf("2 ");
        }
        else if(0==ar[i])
        {
            printf("0 ");
        }
    }
    return 0;
}