#include "Matrix/MatrixGeneration.h"
#include "Matrix/MatrixMultiplication.h"
#include "Verification/Verification.h"

int main() {
    int numRows, numColumns, numNonZeros;
    std::map<int, std::vector<MatrixElement>> matrix = generateMatrix(numRows, numColumns, numNonZeros);
    std::vector<double> multVector = generateVector(numRows);
    std::vector<double> result = multiply(matrix, multVector, numRows);
    //TODO add reference implementation and perform verification
    bool correct = verifySolution(matrix, multVector, result, numRows, numColumns, numNonZeros);
    if (!correct) {
        std::cout << "Incorrect calculation\n";
    } else {
        std::cout << "Correct results\n";
    }
    return 0;
}
