#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10];
    int transpose[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    // Input size of first matrix
    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);

    // Input size of second matrix
    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);

    // Check multiplication condition
    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }

    // Input elements of first matrix
    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements of second matrix
    printf("Enter elements of second matrix:\n");
    for(i = 0; i < r2; i++) {
        for(j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix Multiplication
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display multiplication result
    printf("\nMultiplication Result:\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Transpose of first matrix
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c1; j++) {
            transpose[j][i] = A[i][j];
        }
    }

    // Display transpose
    printf("\nTranspose of First Matrix:\n");
    for(i = 0; i < c1; i++) {
        for(j = 0; j < r1; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}