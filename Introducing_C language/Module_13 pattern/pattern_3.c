#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d",&n);
    k=n;//k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=n;j<=k;j++)//j=1;j++;
        {
            printf("%d",j);
        }
        printf("\n");
        k--;
        
    }
    return 0;
}