#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int p=((n-1)/2)+11;
    int k=1;
    int s=(n+10-1)/2;
    for(int i=1;i<=p;i++)
    {
        for(int j=1;j<=s;j++)
        {
            printf(" ");
        }
        for(int j=1;j<=k;j++)
        {
            printf("*");
        }
        printf("\n");
        if(i<(n+11)/2)
        {
            k=k+2;
            s--;
        }
        else
        {
            k=n;
            s=5;
        }
    }
    return 0;
}
