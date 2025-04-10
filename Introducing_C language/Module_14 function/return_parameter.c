#include<stdio.h>
/*return_type name(parameter)
   {
    code 
    return what?
   }*/
   int sum(int x,int y)
   {
    //code
    int sum=x+y;
    return sum;
   }
int main()
{
    int a,b;//int x,y;->>ekhaner x,y ar uporer ta same na.
    scanf("%d %d",&a,&b);//scanf("%d %d",&x,&y);
    int s=sum(a,b);
    printf("%d\n",s);
    //printf("%d\n",sum(100,2900));
    return 0;
}