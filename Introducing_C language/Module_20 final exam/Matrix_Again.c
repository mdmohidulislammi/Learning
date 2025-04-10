#include<stdio.h>
int main()
{
    int row,col;
    scanf("%d %d",&row,&col);
    int a[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<=col;i++)
    {
        if(i<col)
        {
            printf("%d ",a[row-1][i]);
        }
        if(i==col)
        {
            printf("\n");
        }
    }
    for(int i=0;i<=row;i++)
    {
         if(i<row)
        {
            printf("%d ",a[i][col-1]);
        }
        if(i==row)
        {
            printf("\n");
        }
    }
    return 0;
}