#include "MatrixElement.h"
MatrixElement::MatrixElement() {
    this->rowNumber = 0;
    this->columnNumber = 0;
    this->value = 0;
}

MatrixElement::MatrixElement(int rowNumber, int columnNumber) {
    this->rowNumber = rowNumber;
    this->columnNumber = columnNumber;
    this->value = 0;
}

MatrixElement::MatrixElement(int rowNumber, int columnNumber, double value) {
    this->rowNumber = rowNumber;
    this->columnNumber = columnNumber;
    this->value = value;
}

int MatrixElement::getColumnNumber() {
    return columnNumber;
}

int MatrixElement::getRowNumber() {
    return rowNumber;
}

double MatrixElement::getValue() {
    return value;
}

void MatrixElement::setColumnNumber(int columnNumber) {
    this->columnNumber = columnNumber;
}

void MatrixElement::setRowNumber(int rowNumber) {
    this->rowNumber = rowNumber;
}

void MatrixElement::setValue(double value) {
    this->value = value;
}