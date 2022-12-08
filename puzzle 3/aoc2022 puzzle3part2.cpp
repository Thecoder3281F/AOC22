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

char same_character(string first_str, string second_str, string third_str) {
    for (char c : first_str) {
        // Check if the current character exists in s2 and s3
        if (second_str.find(c) != string::npos && third_str.find(c) != string::npos) {
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


    vector<string> lines;

    while (getline(my_file, line)) {
        lines.push_back(line);

        if (lines.size() == 3) {
            // Process the group of three lines
            duplicated_letter = same_character(lines[0], lines[1], lines[2]);
            priority_value = priority_converter(duplicated_letter);

            sum += priority_value;

            // Clear the lines vector
            lines.clear();
        }
    }

    cout << "The sum is: " << sum << endl;
}
