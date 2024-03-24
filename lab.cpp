#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX = 10; 


void readMatrix(int matrix[MAX][MAX], int& size, const std::string& filename) {
    std::ifstream file(filename);
    file >> size; 
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j]; 
        }
    }
    file.close();
}

void printMatrix(const int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void matrixAdder(const int matrix1[MAX][MAX], const int matrix2[MAX][MAX], int result[MAX][MAX], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixMult(const int matrix1[MAX][MAX], const int matrix2[MAX][MAX], int result[MAX][MAX], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0; 
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}


void matrixSub(const int matrix1[MAX][MAX], const int matrix2[MAX][MAX], int result[MAX][MAX], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void updateElement(int matrix[MAX][MAX], int row, int col, int value, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = value;
    } else {
        std::cerr << "Invalid row or column index." << std::endl;
    }
}


int getMaxValue(const int matrix[MAX][MAX], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}


void transposeMatrix(const int matrix[MAX][MAX], int size) {
    int transposed[MAX][MAX];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    printMatrix(transposed, size);
}

int main() {
    int matrix1[MAX][MAX];
    int matrix2[MAX][MAX];
    int result[MAX][MAX];
    int size;

    readMatrix(matrix1, size, "matrix_input.txt");

    readMatrix(matrix2, size, "matrix_input.txt");

    matrixAdder(matrix1, matrix2, result, size);
    std::cout << "Sum of matrices:" << std::endl;
    printMatrix(result, size);

    matrixMult(matrix1, matrix2, result, size);
    std::cout << "Product of matrices:" << std::endl;
    printMatrix(result, size);

    matrixSub(matrix1, matrix2, result, size);
    std::cout << "Difference of matrices:" << std::endl;
    printMatrix(result, size);

    updateElement(matrix1, 0, 0, 100, size);
    std::cout << "Updated matrix:" << std::endl;
    printMatrix(matrix1, size);

    std::cout << "Max value of the matrix: " << getMaxValue(matrix1, size) << std::endl;

    std::cout << "Transposed matrix:" << std::endl;
    transposeMatrix(matrix1, size);

    return 0;
}
