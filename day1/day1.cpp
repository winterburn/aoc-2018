#include <string>
#include <iostream>
#include <fstream>
#include "..\input_handler.h"

using namespace std;

int main(){
    vector<string> x;
    vector<int> seen_freqs = {0};
    int freq = 0;
    int freq2 = 0;
    InputHandler IH;
    IH.read_file(".\\day1\\input.txt");
    for(int i = 0; i < IH.input.size(); i++){
        freq += stoi(IH.input[i]);
    }
    cout << "Day 1 part 1: " << freq << "\n";
    int j = 0;
    while(true){
        freq2 += stoi(IH.input[j]);
        if (find(seen_freqs.begin(), seen_freqs.end(), freq2) != seen_freqs.end())
            {
                cout << "Day 1 part 2: " << freq2;
                break;
            }
        seen_freqs.push_back(freq2);
        j++;
        if (j > IH.input.size() - 1) j = 0;
    }
    return 0;
}