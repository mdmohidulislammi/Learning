#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d",&n);
    k=n;//k=1;
     for(int i=0;i<n;i++)
     { 
        for(int j=1;j<=k;j++)
        {
            printf("* ");
        }
        printf("\n");
        k--;//k++;
     }
    return 0;
}