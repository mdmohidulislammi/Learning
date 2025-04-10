#include<stdio.h>
#include<string.h>
int main()
{
    int x=100;
    int *ptr=&x;
    x=200;
    *ptr=200;//x-> *ptr same
    printf("x er value - %d\n",x);
    printf("x er value - %d\n",*ptr);
 /*   printf("x er address - %p\n",&x);
    printf("pyr er value - %p\n",ptr);
    printf("ptr er value - %p\n",&ptr);
    printf("ptr er memory size - %d\n",sizeof(ptr));*/
    return 0;
}