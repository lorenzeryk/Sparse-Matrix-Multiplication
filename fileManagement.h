#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_FILEMANAGEMENT_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_FILEMANAGEMENT_H
#include <iostream>
#include <fstream>
#include <string>

void loadFile();
std::string skipCommentedLines(std::ifstream &fileLoader);
void getMatrixInfo(int &numRows, int &numColumns, int &numNonZeros, std::string currentLine);
#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_FILEMANAGEMENT_H
