#include<stdio.h>
long long int fun(int n)
{
    if(n==0) return 1;
    long long int m=fun(n-1);
    return m*n;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int m=fun(n);
    printf("%lld",m);
    return 0;
}