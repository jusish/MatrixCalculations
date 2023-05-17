#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

void multiply(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void matrixPower(int matrix[][MAX_SIZE], int size, int power, int result[][MAX_SIZE]) {
    if (power == 0) {
        // Identity matrix
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = (i == j) ? 1 : 0;
            }
        }
        return;
    }
    
    int temp[MAX_SIZE][MAX_SIZE];
    matrixPower(matrix, size, power - 1, temp);
    multiply(matrix, temp, result, size);
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size, power;
    
    cout << "Enter the size of the matrix: ";
    cin >> size;
    
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Enter the element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "Enter the power: ";
    cin >> power;
    
    int result[MAX_SIZE][MAX_SIZE];
    matrixPower(matrix, size, power, result);
    
    cout << "The result matrix is:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
