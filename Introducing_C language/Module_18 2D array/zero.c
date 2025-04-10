#include<stdio.h>
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int s=r*c;
    int a[r][c],p=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
        for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           if(a[i][j]==0)
           {
            p++;
           }
        }
    }
    if(s==p)
    {
        printf("Zero");
    }
    else
    {
        printf("Not Zero");
    }
    return 0;
}