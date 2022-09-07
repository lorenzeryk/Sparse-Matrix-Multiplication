# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o fileManagement.o
	$(CC) $(CFLAGS) -o main main.o fileManagement.o

# The main.o target can be written more simply

main.o: main.cpp fileManagement.h
	$(CC) $(CFLAGS) -c main.cpp

fileManagement.o: fileManagement.h