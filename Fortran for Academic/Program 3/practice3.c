#include <stdio.h>
int main()
{
    int times;
    printf("Give the n th times : ");
    scanf("%d", &times);
    int a, b;
    printf("Give the first value : ");
    scanf("%d", &a);
    printf("Here is the table : \n");
    for (int i = 1; i <= times; i++)
    {
        printf("%d * %d = %d\n", a, i, a * i);
    }

    return 0;
}