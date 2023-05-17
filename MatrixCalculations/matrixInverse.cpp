#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void printMatrix(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(10) << fixed << setprecision(2) << matrix[i][j];
        }
        cout << endl;
    }
}

bool inverseMatrix(double** matrix, int size, double** inverse) {
    double temp;
    int i, j, k;
    double** identity = new double*[size];
    for (i = 0; i < size; i++) {
        identity[i] = new double[size];
        for (j = 0; j < size; j++) {
            if (i == j) {
                identity[i][j] = 1;
            } else {
                identity[i][j] = 0;
            }
        }
    }

    for (i = 0; i < size; i++) {
        if (matrix[i][i] == 0) {
            for (j = i + 1; j < size; j++) {
                if (matrix[j][i] != 0) {
                    double* temp_row = matrix[i];
                    matrix[i] = matrix[j];
                    matrix[j] = temp_row;

                    temp_row = identity[i];
                    identity[i] = identity[j];
                    identity[j] = temp_row;

                    break;
                }
            }
            if (j == size) {
                return false;
            }
        }

        temp = matrix[i][i];
        for (j = 0; j < size; j++) {
            matrix[i][j] /= temp;
            identity[i][j] /= temp;
        }

        for (j = 0; j < size; j++) {
            if (j != i) {
                temp = matrix[j][i];
                for (k = 0; k < size; k++) {
                    matrix[j][k] -= matrix[i][k] * temp;
                    identity[j][k] -= identity[i][k] * temp;
                }
            }
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            inverse[i][j] = identity[i][j];
        }
    }

    for (i = 0; i < size; i++) {
        delete[] identity[i];
    }
    delete[] identity;

    return true;
}

int main() {
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    double** matrix = new double*[size];
    double** inverse = new double*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        inverse[i] = new double[size];
        for (int j = 0; j < size; j++) {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }

    if (inverseMatrix(matrix, size, inverse)) {
        cout << "\nOriginal Matrix:\n";
        printMatrix(matrix, size);

        cout << "\nInverse Matrix:\n";
        printMatrix(inverse, size);
    } else {
        cout << "Error: The matrix is not invertible.\n";
    }

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
        delete[] inverse[i];
    }
    delete[] matrix;
    delete[] inverse;

    return 0;
}
