#include <iostream>
#include <map>
#include "..\input_handler.h"

using namespace std;

// Day 2 problem https://adventofcode.com/2018/day/2

bool check_for_n_letters(string &word, int count) {
    map<char, int> letters;
    for (int j = 0; j < word.size(); j++){
        if(letters.count(word[j])){
            letters[word[j]] += 1;
        }
        else letters[word[j]] = 1;
    }
    for (const auto &[k, v] : letters)
        {
            if(v == count) return true;
        }
    return false;
}

int solve_part1(vector<string> &input) {
    int counts_of_2 = 0;
    int counts_of_3 = 0;
    for (int i = 0; i < input.size(); i++) {
        if (check_for_n_letters(input[i], 2)) counts_of_2++;
        if (check_for_n_letters(input[i], 3)) counts_of_3++;
    }
    return counts_of_2 * counts_of_3;
}

int check_for_different_letter(string &word1, string &word2){
    /*Check for exactly one different letter and return its index
    "If more or none found return -1*/
    int count = 0;
    int index = 0;
    for(int i = 0; i < word1.size(); i++){
        if (word1[i] != word2[i]) {count++; index = i;}
    }
    if (count == 1) return index;
    else return -1;
}

string solve_part2(vector<string> &input){
    for (int i = 0; i < input.size(); i++){
        for (int j = 0; j < input.size(); j++) {
            int idx = check_for_different_letter(input[i], input[j]);
            if (idx > 0) {input[i].erase(idx, 1); return input[i];}
        }
    }
    return "not found";
}

void main()
{
    InputHandler IH;
    IH.read_file(".\\day2\\input.txt");
    cout << "Day 2 part 1 answer: " << solve_part1(IH.input) << endl;
    cout << "Day 2 part 2 answer: " << solve_part2(IH.input);
}
