#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int s=n-1,k=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=s;j>=1;j--)
        {
            printf(" ");
        }
        for(int j=1;j<=k;j++)
        {
            printf("*");
        }
        printf("\n");
        k=k+2;
        s--;
    }
    return 0;
}