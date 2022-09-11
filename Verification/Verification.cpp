#include "Verification.h"

bool verifySolution(std::map<int, std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, std::vector<double> &result, int &numRows, int &numColumns) {
    alglib::real_2d_array refMatrix = generateRefMatrix(matrix, numRows, numColumns);
    alglib::real_1d_array refVector = generateRefVector(multVector, numRows);
    alglib::real_1d_array refSolution;
    refSolution.setlength(numRows);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Starting ref multiplication\n";
    alglib::rmatrixgemv(numRows, numColumns, 1.0, refMatrix, 0, 0, 0, refVector, 0, 0, refSolution, 0);
    std::cout << "Finished ref multiplication\n";

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Reference multiplication execution time was: " << duration.count() << " microseconds\n";
    bool match = compareSolutions(result, refSolution);
    return match;
}

alglib::real_2d_array generateRefMatrix(std::map<int, std::vector<MatrixElement>> &matrix, int &numRows, int &numColumns) {
    alglib::real_2d_array refMatrix;

    refMatrix.setlength(numRows, numColumns);

    std::map<int, std::vector<MatrixElement>>::iterator it;
    for (it = matrix.begin(); it != matrix.end(); it++) {
        std::vector<MatrixElement> tempRowVector = it->second;
        for (int i = 0; i < tempRowVector.size(); i++) {
            int currentRow = tempRowVector.at(i).getRowNumber();
            int currentColumn = tempRowVector.at(i).getColumnNumber();
            refMatrix[currentRow-1][currentColumn-1] = tempRowVector.at(i).getValue();
        }
    }
    return refMatrix;
}

alglib::real_1d_array generateRefVector(std::vector<double> &multVector, int numRows) {
    alglib::real_1d_array refVector;
    refVector.setlength(numRows);
    for (int i = 0; i < multVector.size(); i++) {
        refVector[i] = multVector.at(i);
    }
    return refVector;
}

bool compareSolutions(std::vector<double> &result, alglib::real_1d_array &refResult) {
    bool match = true;
    for (int i = 0; i < result.size(); i++) {
        if (result.at(i) != refResult[i]) {
            std::cout << "Row number: " << i << " Solution: " << result.at(i) << " Ref: " << refResult[i] << "\n";
            match = false;
        }
    }
    return match;
}