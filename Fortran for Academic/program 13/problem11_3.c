#include <stdio.h>

int main() {
    int n, i, j, k;
    
    // Read matrix size
    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    // Input matrix A
    printf("Enter elements of matrix A:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize matrix C with zeros
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    // Matrix multiplication logic: C = A * B
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the result matrix C
    printf("Resultant matrix C (A * B):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
