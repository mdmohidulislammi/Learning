
#include <stdio.h>
#include <math.h>

int main()
{
    int n, fib = 1, prev = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", &prev);
        int temp = prev;
        prev = prev + fib;
        fib += temp;
    }
    return 0;
}