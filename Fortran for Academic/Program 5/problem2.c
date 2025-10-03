#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter three numbers to get the largest : ");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
    {
        if (a > c)
            printf("%d is the largest number.", a);
        else
            printf("%d is the largest number .", c);
    }
    else
    {
        if (b > c)
            printf("%d is the largest number.", b);
        else
            printf("%d is the largest number . ", c);
    }
    printf("Thanks for using my program.");
    return 0;
}