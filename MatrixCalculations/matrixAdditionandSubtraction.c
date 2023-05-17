#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void addMatrices(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
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

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Error: The dimensions of the matrices must be the same for addition/subtraction.\n");
        return 1;
    }

    printf("\nMatrix 1:\n");
    printMatrix(matrix1, rows1, cols1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    addMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, result);
    printf("\nAddition of the two matrices:\n");
    printMatrix(result, rows1, cols1);

    subtractMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, result);
    printf("\nSubtraction of the two matrices:\n");
    printMatrix(result, rows1, cols1);

    return 0;
}
