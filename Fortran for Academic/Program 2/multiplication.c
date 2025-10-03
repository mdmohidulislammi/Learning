#include <stdio.h>
int main()
{
    float num1, num2, mult;
    printf("Please Enter two number : ");
    scanf("%f %f", &num1, &num2);
    mult = num1 * num2;
    printf("Here is your result : %.3f\nThanks for using my program", mult);
    return 0;
}