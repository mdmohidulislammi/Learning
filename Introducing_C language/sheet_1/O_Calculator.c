#include<stdio.h>
int main()
{
    int a,b,sum,mul,div,dif;
    char c1='+',c2='-',c3='*',c4='/';
     scanf("%d%c%d %d%c%d %d%c%d %d%c%d",&a,&c1,&b,&a,&c2,&b,&a,&c3,&b,&a,&c4,&b);
      sum=a+b;
      dif=a-b;
      mul=a*b;
      div=a/b;
      if(scanf("%d%c%d",&a,&c1,&b))
      {
        printf("%d",sum);
      }
     else if(scanf("%d%c%d",&a,&c2,&b))
      {
        printf("%d",dif);
      }
    return 0;
}