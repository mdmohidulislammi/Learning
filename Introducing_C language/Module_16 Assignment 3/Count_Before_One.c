#include<stdio.h>
int count_before_one(int a[],int x)
{
    int p=0;
    for(int i=0;i<x;i++)
    {
       if(a[i]==1)
       {
        break;
       }
       else if(a[i]!=1)
       {
        p++;
       }
    }
    return p;
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
    int p=count_before_one(a,n);
    printf("%d",p);
    return 0;
}