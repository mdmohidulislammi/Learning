#include<stdio.h>
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int n,p=0;
    scanf("%d",&n);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]==n)
            {
                p=1;           
            }
        }
    }
    if(p==1)
    {
        printf("will not take number");
    }
    else
    {
        printf("will take number");
    }
    return 0;
}