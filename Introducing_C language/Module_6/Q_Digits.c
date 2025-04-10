#include<stdio.h>
int main()
{
    int n,a,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        do 
        {
            printf("%d ",a%10);
           a=a/10;
        }
        while(a!=0);
        printf("\n");
    }
    return 0;
}