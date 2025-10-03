#include<stdio.h>

int main()
{
    int a,b,c,d;
    float ratio;
    printf("Enter four numbers for calculation : ");
    scanf("%d %d %d %d", &a,&b,&c,&d);
    if(c-d !=0)
    {
        ratio = (float)(a+b)/(float)(c-d);
        printf("The ratio is : %f", ratio);
    }
    printf("Thanks for using my program.");
    return 0;
}