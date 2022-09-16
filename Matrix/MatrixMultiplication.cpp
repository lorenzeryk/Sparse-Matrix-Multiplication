#include "MatrixMultiplication.h"
void multiply(std::vector<std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, int numRows, std::vector<double> &result) {
    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for shared(matrix, multVector, result) default(none)
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix.at(i).size() > 0) {
            double rowResult = multiplyRow(matrix.at(i), multVector);
            result.at(i) = rowResult;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Multiplication execution time was: " << duration.count() << " ms\n";
}

double multiplyRow(std::vector<MatrixElement> &row, std::vector<double> &multVector) {
    double sum = 0.0;
    for (int i = 0; i < row.size(); i++) {
        double vectorValue = multVector.at(row.at(i).getColumnNumber()-1);
        sum += row.at(i).getValue()*vectorValue;
    }
    return sum;
}