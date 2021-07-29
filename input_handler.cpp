#include "input_handler.h"
#include <iostream>
#include <fstream>

void InputHandler::read_file(std::string path)
{
    std::vector<std::string>::iterator it;
    it = InputHandler::input.begin();
    std::ifstream inputFile;
    std::string line;
    inputFile.open(path);
    while(std::getline(inputFile, line)) {
        InputHandler::input.insert(it, line);
        it = InputHandler::input.end();
    }
    inputFile.close();
}