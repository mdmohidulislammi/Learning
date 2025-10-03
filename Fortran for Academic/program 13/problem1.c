#include<stdio.h>
int main()
{
    int n=5;
    int a[n];
    long long int sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        sum=sum+a[i]*a[i];
    }
    printf("This is the sum of the 10 th number : %ld", sum);
    return 0;
}