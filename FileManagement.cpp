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

    //TODO read rest of file
    //use array of size numRows? too large of an array
    //map? vector? hashmap?
    //map key could be row number. would allow for empty rows to be negated. would need to search map each time?
    //vector how store row number?
    //hashmap
    std::map<int, std::vector<MatrixElement>> matrix;

    while (!fileLoader.eof()) {
        int rowNumber, columnNumber;
        fileLoader >> rowNumber >> columnNumber;
        MatrixElement tempElement = MatrixElement(columnNumber);
        if (rowNumber == 7361) {

        }

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
    }

    std::vector<MatrixElement> test = matrix.at(7361);
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