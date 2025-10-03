#include <stdio.h>
int main() {
    int num, i;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Display multiplication table
    printf("Multiplication table of %d:\n", num);
    for (i = 1; i <= 10; ++i) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    return 0;
}
