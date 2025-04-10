#include<stdio.h>
int main()
{
    int n,i,count=0,cnt=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0 && a[i]%3==0)
        {
            count++;
        }
        else if(a[i]%2==0)
        {
            count++;
        }
        else if(a[i]%3==0)
        {
            cnt++;
        }
    }
    printf("%d %d",count,cnt);
    return 0;

}