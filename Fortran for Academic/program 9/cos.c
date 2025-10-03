#include <stdio.h>
#include <math.h>

#define ACCURACY 0.000001

double compute_cos(double x) {
    double term = 1, sum = 1;
    int i = 1;

    do {
        term *= -1 * x * x / ((2 * i - 1) * (2 * i));
        sum += term;
        i++;
    } while (fabs(term) > ACCURACY);

    return sum;
}

int main() {
    double x;
    printf("Enter value of x (in radians): ");
    scanf("%lf", &x);

    printf("cos(%.4f) = %.10f\n", x, compute_cos(x));
    return 0;
}
