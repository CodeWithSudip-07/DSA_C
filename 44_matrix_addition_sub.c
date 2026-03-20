#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10], D[10][10];
    int r, c, i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &r, &c);

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &B[i][j]);

    // Addition and Subtraction
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];   // Addition
            D[i][j] = A[i][j] - B[i][j];   // Subtraction
        }
    }

    printf("\nAddition of matrices:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\nSubtraction of matrices (A - B):\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}