#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int row, col;
    printf("Enter the row and col : ");
    scanf("%d %d", &row, &col);
    int prod[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            prod[i][j] = (i + 1) * (j + 1);
        }
    }
    printf("    ");
    for(int i=1;i<row+1;i++)
    {
        printf("%d  ", i);
    }
    printf("\n-------------------------------------------------\n");

    for (int i = 0; i < row; i++)
    {
        printf("%d | ", i+1);
        for (int j = 0; j < col; j++)
            printf("%d  ", prod[i][j]);
        printf("\n");
    }
    return 0;
}