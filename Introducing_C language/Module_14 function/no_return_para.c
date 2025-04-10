#include<stdio.h>
void sum(int a,int b)
{
    int s=a+b;
    printf("%d\n",s);
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    sum(x,y);//-->> ekhon kono variable e rakha lagbe na.
    return 0;
}