#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int ar[n+1],i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    int pos,value;
    scanf("%d %d",&pos,&value);
    for(i=n;i>=pos+1;i--)
    {
        ar[i]=ar[i-1];
    }
    ar[pos]=value;
    for(i=0;i<=n;i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;
}