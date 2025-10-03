#include<stdio.h>
#include<math.h>
int main()
{
    int row1, col1;
    printf("Enter the first row and column : ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the second row and column : ");
    int row2, col2;
    scanf("%d %d", &row2, &col2);
    int a[row1][col1], b[row2][col2];
    if(row1==row2 && col1 ==col2)
    {
        long long int mult[row1][col1];
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {
                printf("a[%d][%d]: ", i,j);
                scanf("%d", &a[i][j]);
            }
        }
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {
                printf("b[%d][%d]: ", i,j);
                scanf("%d", &b[i][j]);
            }
        }
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {
                mult[i][j]=0;
            }
        }
        for(int i=0;i<row1;i++)
        {
            for (int j=0;j<col1;j++)
            {
                for(int k=0;k<col1;k++)
                {
                    mult[i][j]=mult[i][j]+a[i][k]*b[k][j];
                }
            }
        }
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {
                printf("%ld\t", mult[i][j] );
            }
            printf("\n");
        }

    }
    return 0;
}