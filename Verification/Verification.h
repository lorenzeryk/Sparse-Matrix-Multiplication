#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_VERIFICATION_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_VERIFICATION_H

#include <map>
#include "../Matrix/MatrixElement.h"
#include "ALGLIB/linalg.h"

bool verifySolution(std::map<int, std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, std::vector<double> &result);
alglib::real_2d_array generateRefMatrix(std::map<int, std::vector<MatrixElement>> &matrix);
alglib::real_1d_array generateRefVector(std::vector<double> &multVector);
#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_VERIFICATION_H
