#include<stdio.h>
#include<limits.h>
int main()
{
    int n,i,x,y,p=INT_MAX,q=INT_MIN;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(p>a[i])
        {
            p=a[i];
            x=i;
        }
    if(q<a[i])
    {
        q=a[i];
        y=i;
    }
    }
     int tmp=a[x];
         a[x]=a[y];
         a[y]=tmp;
         for(i=0;i<n;i++)
         {
            printf("%d ",a[i]);
         }     
    return 0;
}