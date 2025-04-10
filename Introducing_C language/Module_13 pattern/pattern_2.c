#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int s=0,k=(2*n)-1;
   // int s=n-1,k=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            printf(" ");
        }
        for(int j=1;j<=k;j++)
        {
            printf("*");
        }
        //line shesh 
        printf("\n");
        s++;
        k=k-2;
    }
    return 0;
}