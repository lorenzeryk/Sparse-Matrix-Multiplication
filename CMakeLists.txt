cmake_minimum_required(VERSION 3.16)
project(CSCI580_Sparse_Matrix_Multiplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSCI580_Sparse_Matrix_Multiplication main.cpp MatrixElement.cpp MatrixElement.h MatrixGeneration.cpp MatrixGeneration.h)
