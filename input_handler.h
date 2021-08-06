#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <vector>
#include <regex>

class InputHandler
{
    public:
        std::vector<std::string> get_line_regex(int);
        std::string get_line(int);
        void read_file(std::string);
        void set_regex(std::string);
        int input_size;
    private:
        std::regex regex;
        std::vector<std::string> input;
};

#endif