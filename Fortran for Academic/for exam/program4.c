#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    int x, y=1;
    scanf("%d", &x);
    for(int i=0;i<5;i++)
    {
        y*=x;
    }
    printf("%d", y);

    return 0;
}