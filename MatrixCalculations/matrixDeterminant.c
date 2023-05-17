#include <stdio.h>

#define MAX_SIZE 10

double determinant(double matrix[][MAX_SIZE], int size) {
    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double det = 0;
        for (int i = 0; i < size; i++) {
            double submatrix[MAX_SIZE][MAX_SIZE];
            int subrow = 0, subcol = 0;
            for (int j = 1; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    if (k != i) {
                        submatrix[subrow][subcol++] = matrix[j][k];
                        if (subcol == size - 1) {
                            subrow++;
                            subcol = 0;
                        }
                    }
                }
            }
            double sign = (i % 2 == 0) ? 1 : -1;
            det += sign * matrix[0][i] * determinant(submatrix, size - 1);
        }
        return det;
    }
}

int main() {
    int size;
    printf("Enter the size of the square matrix (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    double matrix[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }

    double det = determinant(matrix, size);
    printf("Determinant of the matrix: %.2f\n", det);

    return 0;
}
