#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int s=n-1,k=1,h=1;
    for(int i=1;i<=(2*n)-1;i++)
    {
        for(int j=1;j<=s;j++)
        {
            printf(" ");
        }
        if(i%2!=0)
        {
            for(int j=1;j<=h;j++)
            {
                printf("#");
            }
        }
        else
        {
            for(int j=1;j<=k;j++)
            {
                printf("-");
            }
        }
        if(i<=n-1)
        {
            s--;
            k=k+2;
            h=h+2;
        }
        else
        {
            s++;
            k=k-2;
            h=h-2;
        }
        printf("\n");
    }
    return 0;
}