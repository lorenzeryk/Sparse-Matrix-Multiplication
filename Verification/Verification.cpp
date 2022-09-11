#include "Verification.h"

bool verifySolution(std::map<int, std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, std::vector<double> &result) {
    alglib::real_2d_array refMatrix = generateRefMatrix(matrix);
    alglib::real_1d_array refVector = generateRefVector(multVector);
    //TODO perform multiplication
    //TODO compare ALGLIB result with own result

    return false;
}

alglib::real_2d_array generateRefMatrix(std::map<int, std::vector<MatrixElement>> &matrix) {
    alglib::real_2d_array refMatrix;
    //TODO copy matrix into refMatrix
    return refMatrix;
}

alglib::real_1d_array generateRefVector(std::vector<double> &multVector) {
    alglib::real_1d_array refVector;
    //TODO generate refVector
    return refVector;
}
