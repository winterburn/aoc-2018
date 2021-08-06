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
    InputHandler::input_size = input.size();
    inputFile.close();
}

std::string InputHandler::get_line(int line_number){
    return InputHandler::input[line_number];
}

std::vector<std::string> InputHandler::get_line_regex(int line_number) {
    std::smatch results;
    std::regex_search(InputHandler::input[line_number], results, InputHandler::regex);
    std::vector<std::string> matches;
    for (int i = 1; i < results.size(); i++) {
        matches.push_back(results[i]);
    }
    return matches;
}

void InputHandler::set_regex(std::string regex) {
    InputHandler::regex = std::regex(regex);
}