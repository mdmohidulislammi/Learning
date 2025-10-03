#include <stdio.h>
#include <math.h>

#define ACCURACY 0.000001

double compute_sum_series() {
    double sum = 1.0, term;
    int i = 2;

    do {
        term = pow(1.0 / i, i);
        sum += term;
        i++;
    } while (term > ACCURACY);

    return sum;
}

int main() {
    printf("Series SUM = %.10f\n", compute_sum_series());
    return 0;
}
