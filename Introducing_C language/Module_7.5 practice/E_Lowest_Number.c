#include<stdio.h>
#include<limits.h>
int main()
{
    int a,i,n,p=0;
    int s=INT_MAX;
    scanf("%d",&n);
    int ar[n];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<n;i++)
    {
        if(s>ar[i])
        {
            s=ar[i];
            p=i;
        }
    }
    printf("%d %d",s,p);
    return 0;
}