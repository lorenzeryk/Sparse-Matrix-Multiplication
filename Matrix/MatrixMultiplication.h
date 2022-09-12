#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXMULTIPLICATION_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXMULTIPLICATION_H
#include <vector>
#include <map>
#include <iostream>
#include <chrono>
#include "MatrixElement.h"

std::vector<double> multiply(std::map<int, std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, int numRows, std::vector<double> &result);
double multiplyRow(std::vector<MatrixElement> &row, std::vector<double> &multVector);
#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXMULTIPLICATION_H
