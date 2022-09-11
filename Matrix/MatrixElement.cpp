#include "MatrixElement.h"
MatrixElement::MatrixElement() {
    this->columnNumber = 0;
    this->value = 0;
}

MatrixElement::MatrixElement(int columnNumber) {
    this->columnNumber = columnNumber;
    this->value = 0;
}

MatrixElement::MatrixElement(int columnNumber, double value) {
    this->columnNumber = columnNumber;
    this->value = value;
}

int MatrixElement::getColumnNumber() {
    return columnNumber;
}

double MatrixElement::getValue() {
    return value;
}

void MatrixElement::setColumnNumber(int columnNumber) {
    this->columnNumber = columnNumber;
}

void MatrixElement::setValue(double value) {
    this->value = value;
}