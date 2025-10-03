#include <stdio.h>
int main()
{
    float Temp_F, Temp_C;
    printf("Give the Temperature value in Fahrenheit: ");
    scanf("%f", &Temp_F);
    Temp_C = (5.0 / 9.0) * (Temp_F - 32);
    printf("The Temperature value: %.2f Degree Celcius\n", Temp_C);
    printf("!! Thanks for using my program !!");
    return 0;
}