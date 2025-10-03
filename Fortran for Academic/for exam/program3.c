#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    switch (a>b)
    {
    case 0:
        printf("B is the largest ");
        break;
    
    case 1:
        printf("A is the largest ");
        break;
    
    }
    return 0;
}