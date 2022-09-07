#include "FileManagement.h"
void loadFile() {
    std::string fileName = "InputFiles/NLR.mtx";
    std::ifstream fileLoader;
    fileLoader.open(fileName);

    if (!fileLoader.is_open()) {
        std::cout << fileName << " failed to open\n";
    }

    int numRows, numColumns, numNonZeros;
    std::string matrixInfo = skipCommentedLines(fileLoader);
    getMatrixInfo(numRows, numColumns, numNonZeros, matrixInfo);

    std::map<int, std::vector<MatrixElement> > matrix;

    while (!fileLoader.eof()) {
        srand(time(nullptr));
        int rowNumber, columnNumber;
        fileLoader >> rowNumber >> columnNumber;
        addElementToMatrix(rowNumber, columnNumber, matrix);
    }

    fileLoader.close();
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
    MatrixElement tempElement = MatrixElement(columnNumber, generateRandomNumber());

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