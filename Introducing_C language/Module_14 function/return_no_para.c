#include<stdio.h>
int sum() //-->>sum(void) dile main func e value dile error hobe;
{
    int a,b;
    scanf("%d %d",&a,&b);//parameter na thakle ekhane input nite hobe.
   int  s=a+b;
    return s;
}
int main()
{
    int s=sum();// call kore vitore kichu dile void e null hobe.
    printf("%d",s);
    return 0;
}