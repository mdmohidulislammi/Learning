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
    int p=1;
    if(r!=c)
    {
        p=0;
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==j)
            {
                if(a[i][j]!=1)
                {
                    p=0;
                }
            }
            else
            {
                if(i+j==(r-1))
                {
                    if(a[i][j]!=1)
                    {
                        p=0;
                    }
                }
             else if(a[i][j]!=0)
                {
                    p=0;
                }
            }
        }
    }
    if(p==1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}