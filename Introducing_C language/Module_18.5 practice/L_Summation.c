#include<stdio.h>
long long int fun(int *a,int n,int i)
{
    if(i==n) return 0;
  long long int s=fun(a,n,i+1);
    return s+a[i];
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
   long long int sum=fun(a,n,0);
    printf("%lld",sum);
    return 0;
}