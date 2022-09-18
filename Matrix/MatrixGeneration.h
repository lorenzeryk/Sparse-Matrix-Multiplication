#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXGENERATION_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXGENERATION_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "MatrixElement.h"

void generateMatrix(int &numRows, int &numColumns, int &numNonZeros, std::vector<std::vector<MatrixElement>> &matrix, std::string fileName);
std::string skipCommentedLines(std::ifstream &fileLoader);
void getMatrixInfo(int &numRows, int &numColumns, int &numNonZeros, std::string currentLine);
double generateRandomNumber();
void addElementToMatrix(int rowNumber, int columnNumber, std::vector<std::vector<MatrixElement> > &matrix);
void generateVector(int &numRows, std::vector<double> &multVector);
#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXGENERATION_H
