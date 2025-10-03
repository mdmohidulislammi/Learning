#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
int main()
{

    while (true)
    {
        int choice;
        printf("\n!! Welcome to my Temperature Converter Program !!\n\n Please choose an option : ");
        printf("\n\n1. Celcius to Fahrenheit\n2. Fahrenheit to Celcius\n3.Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            float temp_c;
            printf("Please Enter the Temperature in Celcius: ");
            scanf("%f", &temp_c);
            float temp_f = ((9.0 / 5.0) * temp_c) + 32;
            printf("Here is the converted Temperature %.3f Degree Fahrenheit.", temp_f);
            printf("\n!! Thanks for using my Program !!");
            // break;
        }
        else if (choice == 2)
        {
            float temp_f;
            printf("Please Enter the Temperature in Fahrenheit: ");
            scanf("%f", &temp_f);
            float temp_c = (temp_f - 32) * (5.0 / 9.0);
            printf("Here is the converted Temperature %.3f Degree Celcius.", temp_c);
            printf("\n!! Thanks for using my Program !!\n");
        }
        else if (choice == 3)
        {
            printf("Thanks for approaching this Program.");
            break;
        }
        else
        {
            printf("You may be choosed the wrong number. Please try again...\n");
        }
    }

    return 0;
}