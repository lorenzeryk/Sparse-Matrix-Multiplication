#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXGENERATION_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXGENERATION_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include "MatrixElement.h"

std::map<int, std::vector<MatrixElement>> generateMatrix(int &numRows);
std::string skipCommentedLines(std::ifstream &fileLoader);
void getMatrixInfo(int &numRows, int &numColumns, int &numNonZeros, std::string currentLine);
double generateRandomNumber();
void addElementToMatrix(int rowNumber, int columnNumber, std::map<int, std::vector<MatrixElement> > &matrix);
std::vector<double> generateVector(int &numRows);
#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXGENERATION_H
