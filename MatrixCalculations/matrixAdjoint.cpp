#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

void getCofactor(int matrix[][MAX_SIZE], int temp[][MAX_SIZE], int p, int q, int size) {
    int i = 0, j = 0;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == size - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int matrix[][MAX_SIZE], int size) {
    if (size == 1) {
        return matrix[0][0];
    }
    
    int result = 0;
    int sign = 1;
    int temp[MAX_SIZE][MAX_SIZE];
    
    for (int col = 0; col < size; col++) {
        getCofactor(matrix, temp, 0, col, size);
        result += sign * matrix[0][col] * determinant(temp, size - 1);
        sign = -sign;
    }
    
    return result;
}

void adjointMatrix(int matrix[][MAX_SIZE], int size, int adjoint[][MAX_SIZE]) {
    if (size == 1) {
        adjoint[0][0] = 1;
        return;
    }
    
    int sign = 1;
    int temp[MAX_SIZE][MAX_SIZE];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            getCofactor(matrix, temp, i, j, size);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjoint[j][i] = sign * determinant(temp, size - 1);
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    
    cout << "Enter the size of the matrix: ";
    cin >> size;
    
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Enter the element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }
    
    int adjoint[MAX_SIZE][MAX_SIZE];
    adjointMatrix(matrix, size, adjoint);
    
    cout << "The adjoint matrix is:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << adjoint[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
