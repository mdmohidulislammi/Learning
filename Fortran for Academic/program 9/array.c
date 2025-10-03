#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    int n=2,m=2;
    int mat1[n][m], mat2[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("Enter the index value for matrix 1 [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("Enter the index value for matrix 2  [%d][%d] : ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("The summation of the matrix is : ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}