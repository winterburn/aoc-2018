#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <vector>

class InputHandler
{
    public:
        void read_file(std::string);
        std::vector<std::string> input;
};

#endif