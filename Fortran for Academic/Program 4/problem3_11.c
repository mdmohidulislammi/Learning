#include <stdio.h>
int main()
{
    int distance, fuel;
    printf("Give the distance in Kilometer : ");
    scanf("%d", &distance);
    printf("Enter the fuel consumed in Liter : ");
    scanf("%d", &fuel);
    printf("The mileage of the car is : %.2f km/L.", (1.0 * distance) / fuel);
    return 0;
}