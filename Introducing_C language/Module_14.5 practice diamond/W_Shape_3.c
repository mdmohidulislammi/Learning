#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int s=n-1,k=1;
    for(int i=1;i<=(2*n);i++)
    {
        for(int j=1;j<=s;j++)
        {
            printf(" ");
        }
        for(int j=1;j<=k;j++)
        {
            printf("*");
        }printf("\n");
        
        if(i<=n-1)
        {
            k=k+2;
            s--;
        }
        else if(i==n)
        {
            k=k-0;
            s=s+0;
        }
        else
        {
            k=k-2;
            s++;
        }        
    }
    return 0;
}