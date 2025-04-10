#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    int j=n-1;
    i=0;
    while(i<j)
    {
        int tmp=ar[i];
        ar[i]=ar[j];
        ar[j]=tmp;
        i++;
        j--;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;
}