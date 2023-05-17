#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

int rankOfMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    int rank = 0;
    
    // Perform row reduction using Gaussian elimination
    for (int row = 0; row < rows; row++) {
        // Find the pivot element
        int pivot = matrix[row][rank];
        if (pivot == 0) {
            // If the pivot is zero, search for a non-zero pivot in lower rows
            int pivotRow = -1;
            for (int i = row + 1; i < rows; i++) {
                if (matrix[i][rank] != 0) {
                    pivotRow = i;
                    break;
                }
            }
            
            if (pivotRow != -1) {
                // Swap the current row with the row containing the non-zero pivot
                for (int j = 0; j < cols; j++) {
                    int temp = matrix[row][j];
                    matrix[row][j] = matrix[pivotRow][j];
                    matrix[pivotRow][j] = temp;
                }
                
                pivot = matrix[row][rank];
            }
        }
        
        if (pivot != 0) {
            // Reduce the rows below the pivot row
            for (int i = row + 1; i < rows; i++) {
                int factor = matrix[i][rank] / pivot;
                for (int j = rank; j < cols; j++) {
                    matrix[i][j] -= factor * matrix[row][j];
                }
            }
            
            rank++;
        }
    }
    
    return rank;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    
    cout << "Enter the number of rows: ";
    cin >> rows;
    
    cout << "Enter the number of columns: ";
    cin >> cols;
    
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter the element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }
    
    int rank = rankOfMatrix(matrix, rows, cols);
    
    cout << "The rank of the matrix is: " << rank << endl;
    
    return 0;
}
