#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_FILEMANAGEMENT_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_FILEMANAGEMENT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "MatrixElement.h"

std::map<int, std::vector<MatrixElement>> loadFile();
std::string skipCommentedLines(std::ifstream &fileLoader);
void getMatrixInfo(int &numRows, int &numColumns, int &numNonZeros, std::string currentLine);
double generateRandomNumber();
void addElementToMatrix(int rowNumber, int columnNumber, std::map<int, std::vector<MatrixElement> > &matrix);

#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_FILEMANAGEMENT_H
