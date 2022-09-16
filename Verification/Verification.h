#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_VERIFICATION_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_VERIFICATION_H

#include <iostream>
#include <map>
#include <chrono>
#include "../Matrix/MatrixElement.h"
#include "ALGLIB/linalg.h"

bool verifySolution(std::vector<std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, std::vector<double> &result, int &numRows, int &numColumns, int &numNonZeros);
void generateRefMatrix(std::vector<std::vector<MatrixElement>> &matrix, alglib::sparsematrix &refMatrix,int &numRows, int &numColumns);
alglib::real_1d_array generateRefVector(std::vector<double> &multVector, int numRows);
bool compareSolutions(std::vector<double> &result, alglib::real_1d_array &refResult);
#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_VERIFICATION_H
