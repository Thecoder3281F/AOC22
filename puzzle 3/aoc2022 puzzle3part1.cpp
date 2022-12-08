#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int priority_converter(char letter) {
    string alphabet_conversion = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < alphabet_conversion.length(); i++) {
        if (alphabet_conversion[i] == letter) {
            //cout << letter;
            //cout << i + 1 << endl;
            return i + 1; // since indexes start from 0
        }
    }
}

char same_character(string first_str, string second_str) {
    for (char c : first_str) {
        // Check if the current character exists in s2 and s3
        if (second_str.find(c) != string::npos) {
            return c;
        }
    }
}


int main() {
    string line;
    int sum = 0;
    int priority_value = 0;
    char duplicated_letter;


    ifstream my_file("./input.txt");



    while(getline(my_file, line)){
        string first_half = line.substr(0, line.length() / 2);
        string second_half = line.substr(line.length() / 2);
        duplicated_letter = same_character(first_half, second_half);
        priority_value = priority_converter(duplicated_letter);
        //cout << priority_value << endl;
        sum += priority_value;



    }

    cout << "The sum is: " << sum << endl;
}
