#include<stdio.h>
int main()
{
    int n,i,x,v,a=0;
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    scanf("%d %d",&x,&v);
    for(i=n-1;i>=0;i--)
    {
        if(x==i)
        {
             ar[i]=v;
        }
        printf("%d ",ar[i]);
    }
    return 0;
}