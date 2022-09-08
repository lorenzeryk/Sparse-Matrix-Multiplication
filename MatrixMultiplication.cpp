#include "MatrixMultiplication.h"
std::vector<double> multiply(std::map<int, std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, int numRows) {
    //TODO add multithreading
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<double> result(numRows);

    std::map<int, std::vector<MatrixElement>>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); it++) {
        int currentRow = it->first;
        double rowResult = multiplyRow(it->second, multVector.at(currentRow-1));
        result.at(currentRow-1) = rowResult;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Multiplication execution time was: " << duration.count() << " ms\n";
    return result;
}

double multiplyRow(std::vector<MatrixElement> &row, double vectorValue) {
    double sum = 0.0;
    for (int i = 0; i < row.size(); i++) {
        sum += row.at(i).getValue()*vectorValue;
    }
    return sum;
}