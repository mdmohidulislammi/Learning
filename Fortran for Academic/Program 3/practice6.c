#include<stdio.h>
#include<time.h>
int main()
{
    time_t current_time= time(NULL);
    struct  tm* Local_Time =localtime(&current_time);
    
    printf("The current time is : %02d : %02d : %02d ", Local_Time->tm_hour, Local_Time->tm_min, Local_Time->tm_sec);
    return 0;
}