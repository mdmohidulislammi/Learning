#include <stdio.h>
int main()
{
    int marks;
    printf("Enter the marks : ");
    scanf("%d", &marks);
    if (marks >= 80 && marks <= 100)
        printf("Your grade is Honours .");
    else if (marks >= 60)
        printf("Your grade is First Division .");
    else if (marks >= 50 )
        printf("Your grade is Second Division.");
    else if (marks >= 40)
        printf("Your grade is Third Division . ");
    else if (marks < 40)
        printf("Your grade is Fail .");
    else
        printf("This marks is invalid. Please try again .");
    return 0;
}