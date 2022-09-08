#include <chrono>
#include "MatrixGeneration.h"

std::vector<double> multiply(std::map<int, std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, int numRows);
double multiplyRow(std::vector<MatrixElement> &row, double vectorValue);

int main() {
    int numRows;
    std::map<int, std::vector<MatrixElement>> matrix = generateMatrix(numRows);
    std::vector<double> multVector = generateVector(numRows);
    std::vector<double> result = multiply(matrix, multVector, numRows);
    //TODO add reference implementation and perform verification
    return 0;
}

std::vector<double> multiply(std::map<int, std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, int numRows) {
    //TODO add multithreading
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Beginning multiplication\n";
    std::vector<double> result(numRows);

    std::map<int, std::vector<MatrixElement>>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); it++) {
        int currentRow = it->first;
        double rowResult = multiplyRow(it->second, multVector.at(currentRow-1));
        result.at(currentRow-1) = rowResult;
    }

    std::cout << "Finished multiplication\n";
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "The execution time was: " << duration.count() << " ns\n";
    return result;
}

double multiplyRow(std::vector<MatrixElement> &row, double vectorValue) {
    double sum = 0.0;
    for (int i = 0; i < row.size(); i++) {
        sum += row.at(i).getValue()*vectorValue;
    }
    return sum;
}