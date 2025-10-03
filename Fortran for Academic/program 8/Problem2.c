#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int i=1, k=1;
    do
    {
        int j=1;
        do
        {
            printf("%3d    ", j*i);
            j++;

        } while (j<=10);
        printf("\n");
        i++;        
        
    } while (i<=12);
    

    return 0;
}