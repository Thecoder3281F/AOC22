#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>

using namespace std;

bool containsduplicate(string str) {
    unordered_set<char> characters;
    for (char c : str) {
        if (characters.count(c) > 0) return true; // c is a duplicate
        characters.insert(c);
    }
    return false; // no duplicates were found
}

int posofnoduplicates(int substrlength, string str) {
    for (int i = 0; i <= str.size() - substrlength; i++) {
        string block = str.substr(i, substrlength);
        if (!containsduplicate(block)) {
            return i + substrlength; // Add 1 for the position of the first character in substring (since indexes start at 0), then add length of substring-1 to get the position of the end character
        }
    }
}

int main() {
    ifstream my_file("./input.txt");
    string line;

    while(getline(my_file, line)){
        cout << "Number of characters processed after a substring of length 4 containing no duplicates is found: " << posofnoduplicates(4, line) << endl; // start of packet (part 1)
        cout << "Number of characters processed after a substring of length 14 containing no duplicates is found: " << posofnoduplicates(14, line) << endl; // start of message (part 2)
    }
    my_file.close();
}
