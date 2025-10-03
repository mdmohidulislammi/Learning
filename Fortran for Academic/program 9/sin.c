#include <stdio.h>
#include <math.h>

#define ACCURACY 0.000001

double compute_sin(double x) {
    double term = x, sum = x;
    int i = 1;

    do {
        term *= -1 * x * x / ((2 * i) * (2 * i + 1));
        sum += term;
        i++;
    } while (fabs(term) > ACCURACY);

    return sum;
}

int main() {
    double x;
    printf("Enter value of x (in radians): ");
    scanf("%lf", &x);

    printf("sin(%.4f) = %.10f\n", x, compute_sin(x));
    return 0;
}