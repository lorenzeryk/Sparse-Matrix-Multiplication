cmake_minimum_required(VERSION 3.16)
project(CSCI580_Sparse_Matrix_Multiplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSCI580_Sparse_Matrix_Multiplication main.cpp Matrix/MatrixElement.cpp Matrix/MatrixElement.h Matrix/MatrixGeneration.cpp Matrix/MatrixGeneration.h Matrix/MatrixMultiplication.cpp Matrix/MatrixMultiplication.h Verification/Verification.cpp Verification/Verification.h)
