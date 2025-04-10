#include<stdio.h>
int main()
{
    int a,b,div;
    scanf("%d %d",&a,&b);
    div=a-b;
    if(div>=0)
    {
        printf("%d",div);
    }
    else
    {
        printf("0");
    }
    return 0;
}