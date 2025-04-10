#include<stdio.h>
int main()
{
    int n,i,j,m;
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    scanf("%d",&m);
    int a[m];
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    int arr[m+n];
    for(i=0;i<m+n;i++)
    {
          arr[i]=ar[i];
    }
    i=n;
    for(int j=0;j<m;j++)
    {
        arr[i]=a[j];
        i++;
    }
    for(i=0;i<m+n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}