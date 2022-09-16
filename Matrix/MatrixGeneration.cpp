#include "MatrixGeneration.h"
std::map<int, std::vector<MatrixElement>> generateMatrix(int &numRows, int &numColumns, int &numNonZeros, std::map<int, std::vector<MatrixElement>> &matrix) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string fileName = "InputFiles/delaunay_n19.mtx";
    std::ifstream fileLoader;
    fileLoader.open(fileName);

    if (!fileLoader.is_open()) {
        std::cout << fileName << " failed to open\n";
        exit(-1);
    }

    std::string matrixInfo = skipCommentedLines(fileLoader);
    getMatrixInfo(numRows, numColumns, numNonZeros, matrixInfo);

    srand(time(0));

    while (!fileLoader.eof()) {
        int rowNumber, columnNumber;
        fileLoader >> rowNumber >> columnNumber;
        addElementToMatrix(rowNumber, columnNumber, matrix);
    }

    fileLoader.close();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "Matrix generation execution time was: " << duration.count() << " s\n";
    return matrix;
}

std::vector<double> generateVector(int &numRows, std::vector<double> &multVector) {
    for (int i = 0; i < numRows; i++) {
        multVector.push_back(generateRandomNumber());
    }

    return multVector;
}

std::string skipCommentedLines(std::ifstream &fileLoader) {
    //read file until get past commented lines
    bool commentedLines = true;
    std::string currentLine;
    while (commentedLines) {
        getline(fileLoader, currentLine);
        if (currentLine[0] != '%') {
            commentedLines = false;
        }
    }
    return currentLine; //return last line which contains info on matrix size
}

void getMatrixInfo(int &numRows, int &numColumns, int &numNonZeros, std::string currentLine) {
    int currentIndex = currentLine.find(' ');
    numRows = std::stoi(currentLine.substr(0, currentIndex));
    currentLine.erase(0, currentIndex+1);

    currentIndex = currentLine.find(' ');
    numColumns = std::stoi(currentLine.substr(0, currentIndex));
    currentLine.erase(0, currentIndex+1);

    currentIndex = currentLine.find(' ');
    numNonZeros = std::stoi(currentLine.substr(0, currentIndex));
}

void addElementToMatrix(int rowNumber, int columnNumber, std::map<int, std::vector<MatrixElement> > &matrix) {
    MatrixElement tempElement = MatrixElement(rowNumber, columnNumber, generateRandomNumber());

    //row already exists in map
    if (matrix.count(rowNumber)) {
        std::vector<MatrixElement> tempRow = matrix.at(rowNumber);
        tempRow.push_back(tempElement);
        matrix.at(rowNumber) = tempRow;
    } else {
        std::vector<MatrixElement> tempRow;
        tempRow.push_back(tempElement);
        matrix.emplace(rowNumber, tempRow);
    }

    //insert identical element at corresponding point above diagonal. flip row and column
    tempElement.setColumnNumber(rowNumber);
    tempElement.setRowNumber(columnNumber);
    if (matrix.count(columnNumber)) {
        std::vector<MatrixElement> tempRow = matrix.at(columnNumber);
        tempRow.push_back(tempElement);
        matrix.at(columnNumber) = tempRow;
    } else {
        std::vector<MatrixElement> tempRow;
        tempRow.push_back(tempElement);
        matrix.emplace(columnNumber, tempRow);
    }
}

double generateRandomNumber() {
    double lower = 0.1;
    double upper = 4.9;
    return (rand() / (double)RAND_MAX) * (upper - lower) + lower;
}
