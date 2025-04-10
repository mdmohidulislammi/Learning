#include<stdio.h>
int main()
{
    int n,i,s=0,su=0;
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<n;i++)
    {
        if(ar[i]>=0)
        {
            s=s+ar[i];
        }
        else if(ar[i]<=0)
        {
            su=su+ar[i];
        }
    }
    printf("%d %d",s,su);
    return 0;
}