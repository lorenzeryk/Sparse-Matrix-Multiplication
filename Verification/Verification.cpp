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
    std::map<int, std::vector<MatrixElement>>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); it++) {
        std::vector<MatrixElement> tempRowVector = it->second;
        for (int i = 0; i < tempRowVector.size(); i++) {
            int currentRow = tempRowVector.at(i).getRowNumber();
            int currentColumn = tempRowVector.at(i).getColumnNumber();
            refMatrix[currentRow][currentColumn] = tempRowVector.at(i).getValue();
        }
    }
    return refMatrix;
}

alglib::real_1d_array generateRefVector(std::vector<double> &multVector) {
    alglib::real_1d_array refVector;
    for (int i = 0; i < multVector.size(); i++) {
        refVector[i] = multVector.at(i);
    }
    return refVector;
}
