#include <iostream>
#include <fstream>

void loadFile();

int main() {
    loadFile();
    return 0;
}

void loadFile() {
    std::ifstream fileLoader;
    fileLoader.open("NLR.mtx");
    while (fileLoader.is_open()) {
        bool commentedLines = true;
        std::string test;
        fileLoader >> test;
        char *currentLine;
        while (commentedLines) {
            fileLoader.getline(currentLine, 256);
            char test = *currentLine;
            commentedLines = false;
        }
    }
}