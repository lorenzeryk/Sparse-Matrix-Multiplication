#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXELEMENT_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXELEMENT_H


class MatrixElement {
public:
    MatrixElement();
    MatrixElement(int columnNumber, double value);
    int getColumnNumber();
    double getValue();
    void setColumnNumber(int columnNumber);
    void setValue(double value);
private:
    int columnNumber;
    double value;
};


#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXELEMENT_H
