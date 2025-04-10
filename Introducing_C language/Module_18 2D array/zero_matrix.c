#include<stdio.h>
int main()
{
    int row,col;
    scanf("%d %d",&row,&col);
    int el=row*col,cnt=0;
    int a[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(a[i][j]==0)
            {
                cnt++;
            }
        }
    }
    if(el==cnt)
    {
        printf("Zero matrix\n");
    }
    else
    {
        printf("Not Zero Matrix");
    }

    return 0;
}