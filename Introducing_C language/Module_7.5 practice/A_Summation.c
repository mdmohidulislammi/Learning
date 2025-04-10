#include<stdio.h>
int main()
{
    int n,i;
    long long int sum=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
     if(sum>0)
    {
        printf("%lld",sum);
    }
     else if(sum<0)
    {
        printf("%lld",-sum);
    }
    else if(sum==0)
    {
        printf("%lld",sum);
    }
    return 0;
}