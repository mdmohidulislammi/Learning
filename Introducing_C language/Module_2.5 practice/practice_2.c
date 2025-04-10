#include<stdio.h>
int main()
{
    int a,b,sum,dif,mul;
    float div;
    scanf("%d %d",&a,&b);
    sum=a+b;
    dif=a-b;
    mul=a*b;
    div=(float)a/b;
    printf("%d+%d=%d\n",a,b,sum);
    printf("%d-%d=%d\n",a,b,sum);
    printf("%d*%d=%d\n",a,b,mul);
    printf("%d/%d=%f",a,b,div);
    return 0;
}