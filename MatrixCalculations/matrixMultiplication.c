#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void multiplyMatrices(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
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
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows for matrix 1 (maximum %d): ", MAX_ROWS);
    scanf("%d", &rows1);

    printf("Enter the number of columns for matrix 1 (maximum %d): ", MAX_COLS);
    scanf("%d", &cols1);

    printf("Enter the elements of matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows for matrix 2 (maximum %d): ", MAX_ROWS);
    scanf("%d", &rows2);

    printf("Enter the number of columns for matrix 2 (maximum %d): ", MAX_COLS);
    scanf("%d", &cols2);

    printf("Enter the elements of matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    if (cols1 != rows2) {
        printf("Error: The number of columns in matrix 1 must be equal to the number of rows in matrix 2.\n");
        return 1;
    }

    multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, result);

    printf("\nThe product of the two matrices is:\n");
    printMatrix(result, rows1, cols2);

    return 0;
}
