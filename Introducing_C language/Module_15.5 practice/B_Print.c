#include<stdio.h>
void fun(int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d",i);
        if(i<n)
        {
            printf(" ");
        }
    }
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    fun(n);
    return 0;
}