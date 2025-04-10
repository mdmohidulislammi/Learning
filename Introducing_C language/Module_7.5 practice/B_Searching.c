#include<stdio.h>
int main()
{
    int a,i,n,ans=-1;
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    scanf("%d",&a);
    for(i=0;i<n;i++)
    {
        if(a==ar[i])
        {
            ans=i;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}