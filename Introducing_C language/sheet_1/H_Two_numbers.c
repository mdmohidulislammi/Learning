#include<stdio.h>
int main()
{
    int a,b,fl,ce,round,ceil;
    float un;
    scanf("%d %d",&a,&b);
    un=(a*1.0)/b;
    fl=a/b;
    ce=a/b+1;
    if(ce-un >.5)
    {
        round=a/b;
    }
    else if(ce-un <=.5)
    {
        round=a/b +1;
    }
    if(a%b==0)
    {
        ceil=fl;
    }
    else if(a%b != 0)
    {
        ceil=ce;
    }
    printf("floor %d / %d = %d\nceil %d / %d = %d\nround %d / %d = %d",a,b,fl,a,b,ceil,a,b,round);
    return 0;
}