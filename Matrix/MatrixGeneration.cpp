#include "MatrixGeneration.h"
void generateMatrix(int &numRows, int &numColumns, int &numNonZeros, std::vector<std::vector<MatrixElement>> &matrix, std::string fileName) {
    std::ifstream fileLoader;
    fileLoader.open(fileName);

    if (!fileLoader.is_open()) {
        std::cout << fileName << " failed to open\n";
        exit(-1);
    }

    std::string matrixInfo = skipCommentedLines(fileLoader);
    getMatrixInfo(numRows, numColumns, numNonZeros, matrixInfo);
    matrix = std::vector<std::vector<MatrixElement>> (numRows);

    srand(time(0));

    while (!fileLoader.eof()) {
        int rowNumber, columnNumber;
        fileLoader >> rowNumber >> columnNumber;
        addElementToMatrix(rowNumber, columnNumber, matrix);
    }

    fileLoader.close();
}

void generateVector(int &numRows, std::vector<double> &multVector) {
    for (int i = 0; i < numRows; i++) {
        multVector.push_back(generateRandomNumber());
    }
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

void addElementToMatrix(int rowNumber, int columnNumber, std::vector<std::vector<MatrixElement> > &matrix) {
    MatrixElement tempElement = MatrixElement(rowNumber, columnNumber, generateRandomNumber());

    //row already exists in map
    matrix.at(rowNumber-1).push_back(tempElement);

    //insert identical element at corresponding point above diagonal. flip row and column
    tempElement.setColumnNumber(rowNumber);
    tempElement.setRowNumber(columnNumber);
    matrix.at(rowNumber-1).push_back(tempElement);
}

double generateRandomNumber() {
    double lower = 0.1;
    double upper = 4.9;
    return (rand() / (double)RAND_MAX) * (upper - lower) + lower;
}
