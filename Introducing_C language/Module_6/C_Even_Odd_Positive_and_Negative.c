#include<stdio.h>
int main()
{
    int n,a,i,even=0,odd=0,pos=0,neg=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a%2==0)
        {
            //even
            even=even+1;
        }
        else 
        {
           // odd
           odd=odd+1;
        }
        if(a>0)
        {
            //pos
            pos=pos+1;
        }
        else if(a<0)
        {
            //neg
            neg=neg+1;
        }
    }
    printf("Even: %d\nOdd: %d\nPositive: %d\nNegative: %d",even,odd,pos,neg);
    return 0;
}