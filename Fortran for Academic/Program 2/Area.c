#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    float s, Area;
    printf("Enter three sides of the triangle : ");
    scanf("%d %d %d", &a,&b,&c);
    s=(a+b+c)/2.0;
    Area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Here is the Area of the triangle : %.2f",
         Area);
    printf("\nThanks for using this program .");
    return 0;
}