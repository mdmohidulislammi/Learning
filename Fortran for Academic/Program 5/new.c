#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>
#define money 2000
int main()
{
    char c[50];
    printf("Enter the name : ");
   
    fgets(c, sizeof(c), stdin);
    printf("Your name is : %s", c);
    return 0;
}