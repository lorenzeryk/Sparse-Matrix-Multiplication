# Makefile for Writing Make Files Example
#TODO update clean function to remove *.o
#TODO create make run
# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g
TARGET=main

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o MatrixGeneration.o MatrixElement.o
	$(CC) $(CFLAGS) -o main main.o MatrixGeneration.o MatrixElement.o

# The main.o target can be written more simply

main.o: main.cpp MatrixGeneration.h MatrixElement.h
	$(CC) $(CFLAGS) -c main.cpp

MatrixGeneration.o: MatrixGeneration.h MatrixElement.h

MatrixElement.o: MatrixElement.h

.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -f *.o