#include "MatrixGeneration.h"
#include "MatrixMultiplication.h"

int main() {
    int numRows;
    std::map<int, std::vector<MatrixElement>> matrix = generateMatrix(numRows);
    std::vector<double> multVector = generateVector(numRows);
    std::vector<double> result = multiply(matrix, multVector, numRows);
    //TODO add reference implementation and perform verification
    return 0;
}
