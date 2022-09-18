#include "Matrix/MatrixGeneration.h"
#include "Matrix/MatrixMultiplication.h"
#include "Verification/Verification.h"

int main(int argc, char *argv[]) {
    int numRows, numColumns, numNonZeros;
    std::vector<std::vector<MatrixElement>> matrix;
    generateMatrix(numRows, numColumns, numNonZeros, matrix, argv[1]);

    std::vector<double> multVector;
    multVector.reserve(numRows);
    generateVector(numRows, multVector);

    std::vector<double> result(numRows);
    int executionTime = multiply(matrix, multVector, numRows, result);

    std::cout << argv[1] << " multiplication execution time was: " << executionTime << " microseconds\n";

    bool correct = verifySolution(matrix, multVector, result, numRows, numColumns, numNonZeros);
    if (!correct) {
        std::cout << "Incorrect calculation\n";
    }
    return 0;
}
