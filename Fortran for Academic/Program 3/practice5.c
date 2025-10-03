#include<stdio.h>
int main()
{
    int Distance, Time;
    printf("Distance in Meter : ");
    scanf("%d", &Distance);
    printf("Time in seconds : ");
    scanf("%d", &Time);
    // float Speed= (1.0*Distance)/Time;
    printf("The speed of the Car : %.2f",(Distance*1.0 / Time));
    return 0;
}