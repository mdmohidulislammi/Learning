#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a<=b && a<=c)
    {
        if(b<=c)
        {
            printf("%d\n%d\n%d",a,b,c);
        }
        else
        {
            printf("%d\n%d\n%d",a,c,b);
        }
    }
    else if(b<=a && b<=c)
    {
         if(a<=c)
        {
            printf("%d\n%d\n%d",b,a,c);
        }
        else
        {
            printf("%d\n%d\n%d",b,c,a);
        }
    }
    else
    {
         if(a<=b)
        {
            printf("%d\n%d\n%d",c,a,b);
        }
        else
        {
            printf("%d\n%d\n%d",c,b,a);
        }
    }
    printf("\n\n%d\n%d\n%d",a,b,c);
    return 0;
}