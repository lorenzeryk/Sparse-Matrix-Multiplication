#include "Matrix/MatrixGeneration.h"
#include "Matrix/MatrixMultiplication.h"
#include "Verification/Verification.h"

int main() {
    int numRows, numColumns, numNonZeros;
    std::map<int, std::vector<MatrixElement>> matrix;
    generateMatrix(numRows, numColumns, numNonZeros, matrix);

    std::vector<double> multVector;
    multVector.reserve(numRows);
    generateVector(numRows, multVector);

    std::vector<double> result(numRows);
    multiply(matrix, multVector, numRows, result);

    bool correct = verifySolution(matrix, multVector, result, numRows, numColumns, numNonZeros);
    if (!correct) {
        std::cout << "Incorrect calculation\n";
    } else {
        std::cout << "Correct results\n";
    }
    return 0;
}
