#include<stdio.h>
#include<limits.h>
void fun(int*a,int n)
{
    int m=INT_MAX,p=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]<m)
        {
            m=a[i];
        }
        if(a[i]>p)
        {
            p=a[i];
        }
    }
    printf("%d %d",m,p);
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
    fun(a,n);
}