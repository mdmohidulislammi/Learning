#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int max_value = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= max_value)
            max_value = a[i];
    }

    printf("The largest number is : %d", max_value);
    return 0;
}