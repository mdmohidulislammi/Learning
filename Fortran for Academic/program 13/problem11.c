#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000000], count = 0;
    printf("Enter any string : ");
    fgets(str, sizeof(str), stdin);
    for (int i = 0; i < 1000000; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            count++;
        else if (str[i] == ' ' || str[i] == '.')
            continue;
        else
            break;
    }
    printf("The length of string : %d", count);
    return 0;
}