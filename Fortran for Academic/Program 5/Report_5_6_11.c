#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter three integer value : ");
    scanf("%d %d %d", &a, &b, &c);
    if (a * a + b * b == c * c){
        printf("Those are right angle triangle's sides.\n");
        printf("The Hypotenuse is : %d", c);
    }
    else if (a * a + c * c == b * b){
        printf("Those are right angle triangle's sides.\n");
        printf("The Hypotenuse is : %d", b);
    }
    else if (b * b + c * c == a * a){
        printf("Those are right angle triangle's sides.\n");
        printf("The Hypotenuse is : %d", a);
    }
    else
        printf("Those are not three sides of right angle triangle.");
    return 0;
}