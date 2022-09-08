#include "MatrixGeneration.h"

int main() {
    int numRows;
    std::map<int, std::vector<MatrixElement>> matrix = generateMatrix(numRows);
    std::vector<double> multVector = generateVector(numRows);
    //TODO multiply matrix and vector. measure execution time
    //TODO add reference implementation and perform verification
    return 0;
}