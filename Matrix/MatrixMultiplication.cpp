#include "MatrixMultiplication.h"
std::vector<double> multiply(std::map<int, std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, int numRows, std::vector<double> &result) {
    //TODO add multithreading
    auto start = std::chrono::high_resolution_clock::now();

    for (std::map <int, std::vector < MatrixElement >> ::iterator it = matrix.begin(); it != matrix.end(); it++) {
        int currentRow = it->first;
        double rowResult = multiplyRow(it->second, multVector);
        result.at(currentRow - 1) = rowResult;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Multiplication execution time was: " << duration.count() << " ms\n";
    return result;
}

double multiplyRow(std::vector<MatrixElement> &row, std::vector<double> &multVector) {
    double sum = 0.0;
    for (int i = 0; i < row.size(); i++) {
        double vectorValue = multVector.at(row.at(i).getColumnNumber()-1);
        sum += row.at(i).getValue()*vectorValue;
    }
    return sum;
}