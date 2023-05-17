#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void transposeMatrix(int matrix[][MAX_COLS], int rows, int cols, int result[][MAX_ROWS]) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}

void printMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS], transpose[MAX_COLS][MAX_ROWS];
    int rows, cols;

    printf("Enter the number of rows for the matrix (maximum %d): ", MAX_ROWS);
    scanf("%d", &rows);

    printf("Enter the number of columns for the matrix (maximum %d): ", MAX_COLS);
    scanf("%d", &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    transposeMatrix(matrix, rows, cols, transpose);

    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, rows, cols);

    printf("\nTranspose Matrix:\n");
    printMatrix(transpose, cols, rows);

    return 0;
}
