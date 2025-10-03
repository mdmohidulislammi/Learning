#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Give the value of a,b,c : ");
    scanf("%d %d %d", &a,&b,&c);
    float x= (a*1.0)/(b-c);
    printf("Here is the output : %.2f", x);
    return 0;
}