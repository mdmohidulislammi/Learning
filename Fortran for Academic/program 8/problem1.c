#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    int n, count=1;
    double y=1.0;
    float x;
    printf("Enter the value of x and n: ");
    scanf("%f %d", &x, &n);
    while (count<=n)
    {
        y=y*x;
        count++;
    }
    printf("The value of x : %f the value of n= %d and x to the power n is = %.2lf", x, n, y);

    return 0;
}