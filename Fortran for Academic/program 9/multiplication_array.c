#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    int n,m,p,q;
    printf("Enter the row and column for the first matrix : ");
    scanf("%d %d", &n,&m);    
    printf("Enter the row and column for the second matrix: ");
    scanf("%d %d", &p,&q);
    int a[n][m], b[p][q];
    if(m==p)
    {
        int mult_array[n][q];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<q;j++)
            mult_array[i][j]=0;
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                printf("First [%d][%d]: ", i,j);
                scanf("%d", &a[i][j]);
            }
        }
        for (int i=0;i<p;i++)
        {
            for (int j=0;j<q;j++)
            {
                printf("Second [%d][%d]: ", i,j);
                scanf("%d", &b[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<q;j++)
            {
                for(int s=0;s<m;s++)
                {
                    mult_array[i][j]=mult_array[i][j]+a[i][s]*b[s][j];
                }
            }
        }
        printf("Here is the multiplication of two array a and  b : \n");
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<q;j++)
            printf("%d  ", mult_array[i][j]);
            printf("\n");
        }

        }
    else
    printf("Multiplication is not possible.");
    return 0;
}