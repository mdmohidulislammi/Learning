#include<stdio.h>
int main()
{
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    if(x<=y && x<=z)
    printf("X is smaller than all :%d",x);
    else if(y<=x && y<=z)
    printf("Y is smaller than all the given number :%d",y);
    else 
    printf("Z is smaller than all given number :%d",z);
   // printf("%d\n%d\n%d\n",x,y,z);
    return 0;
}