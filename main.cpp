#include "Matrix/MatrixGeneration.h"
#include "Matrix/MatrixMultiplication.h"
#include "Verification/Verification.h"

int main() {
    int numRows;
    std::map<int, std::vector<MatrixElement>> matrix = generateMatrix(numRows);
    std::vector<double> multVector = generateVector(numRows);
    std::vector<double> result = multiply(matrix, multVector, numRows);
    //TODO add reference implementation and perform verification
    bool correct = verifySolution(matrix, multVector, result);
    return 0;
}
