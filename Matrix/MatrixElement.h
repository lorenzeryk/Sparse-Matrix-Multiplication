#ifndef CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXELEMENT_H
#define CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXELEMENT_H


class MatrixElement {
public:
    MatrixElement();
    MatrixElement(int rowNumber, int columnNumber);
    MatrixElement(int rowNumber, int columnNumber, double value);
    int getColumnNumber();
    int getRowNumber();
    double getValue();
    void setColumnNumber(int columnNumber);
    void setRowNumber(int rowNumber);
    void setValue(double value);
private:
    int columnNumber;
    int rowNumber;
    double value;
};


#endif //CSCI580_SPARSE_MATRIX_MULTIPLICATION_MATRIXELEMENT_H
