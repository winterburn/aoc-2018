#include <iostream>
#include <regex>
#include <map>
#include  "..\input_handler.h"

using namespace std;

int solve_part_1(){
    vector<vector<int>> fabric;
    int result = 0;
    InputHandler IH;
    IH.read_file(".\\day3\\input.txt");
    IH.set_regex("([1-9].*) @ ([1-9].*),([1-9].*): ([1-9].*)x([1-9].*)");
    int i = 0;
    while (i++ < IH.input_size) {

        vector<string> matches = IH.get_line_regex(i);
        cout << matches[3];
        for (int x = 0; x < stoi(matches[3]); x++){
            cout << matches[3] << " " << x << endl;
            //for (int y = 0; y < stoi(matches[4]); y++) {
            //}
        }
    }
    cout << "hei";
    return result;
}


void main() {
    cout << "Day3 part 1: " << solve_part_1() << endl;
}