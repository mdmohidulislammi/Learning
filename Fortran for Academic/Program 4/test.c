#include <stdio.h>
#include <math.h>
int main()
{
    double x1, y1, x2, y2, distance;
    printf("Enter x1 and y1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter x2 and y2: ");
    scanf("%lf %lf", &x2, &y2);
    distance = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    printf("The distance between the points is: %.2lf\n", distance);
    return 0;
}