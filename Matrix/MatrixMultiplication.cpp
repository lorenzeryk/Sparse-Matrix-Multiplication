#include "MatrixMultiplication.h"
int multiply(std::vector<std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, int numRows, std::vector<double> &result) {
    auto start = std::chrono::high_resolution_clock::now();

    //parallel loop for calculating each row of output vector
    #pragma omp parallel for shared(matrix, multVector, result) default(none)
    for (int i = 0; i < matrix.size(); i++) {
        result.at(i) = multiplyRow(matrix.at(i), multVector);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
}

double multiplyRow(std::vector<MatrixElement> &row, std::vector<double> &multVector) {
    double sum = 0.0;
    for (int i = 0; i < row.size(); i++) {
        sum += row.at(i).getValue()*multVector.at(row.at(i).getColumnNumber()-1);
    }
    return sum;
}