#include "Verification.h"

bool verifySolution(std::vector<std::vector<MatrixElement>> &matrix, std::vector<double> &multVector, std::vector<double> &result, int &numRows, int &numColumns, int &numNonZeros) {
    alglib::setglobalthreading(alglib::parallel);

    alglib::real_1d_array refVector = generateRefVector(multVector, numRows);

    alglib::real_1d_array refSolution;
    refSolution.setlength(numRows); //preallocate reference solution

    alglib::sparsematrix refMatrix;
    alglib::sparsecreate(numRows, numColumns, numNonZeros, refMatrix); //preallocate with nonZeros space
    generateRefMatrix(matrix, refMatrix, numRows, numColumns);
    alglib::sparseconverttocrs(refMatrix); //convert to crs format for compatibility with multiplication function

    try
    {
        alglib::sparsemv(refMatrix, refVector, refSolution);
    }
    catch(alglib::ap_error e)
    {
        printf("error msg: %s\n", e.msg.c_str());
    }

    bool match = compareSolutions(result, refSolution);
    return match;
}

void generateRefMatrix(std::vector<std::vector<MatrixElement>> &matrix, alglib::sparsematrix &refMatrix, int &numRows, int &numColumns) {
    //iterate through entire matrix and add each point
    std::map<int, std::vector<MatrixElement>>::iterator it;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            int currentColumn = matrix.at(i).at(j).getColumnNumber();
            alglib::sparseadd(refMatrix, i, currentColumn-1, matrix.at(i).at(j).getValue());
        }
    }
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
            double epsilon = 0.0000000001; //check if doubles are very close
            if (abs((result.at(i)-refResult[i])) > epsilon) {
                std::cout << "Row number: " << i << " Solution: " << result.at(i) << " Ref: " << refResult[i] << "\n";
                match = false;
            }
        }
    }
    return match;
}