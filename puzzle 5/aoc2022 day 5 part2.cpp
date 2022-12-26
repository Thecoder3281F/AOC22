#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <deque>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream my_file("./input.txt");
    string line;

    deque<string> s1 = {"N", "S", "D", "C", "V", "Q", "T"};
    deque<string> s2 = {"M", "F", "V"};
    deque<string> s3 = {"F", "Q", "W", "D", "P", "N", "H", "M"};
    deque<string> s4 = {"D", "Q", "R", "T", "F"};
    deque<string> s5 = {"R", "F", "M", "N", "Q", "H", "V", "B"};
    deque<string> s6 = {"C", "F", "G", "N", "P", "W", "Q"};
    deque<string> s7 = {"W", "F", "R", "L", "C", "T"};
    deque<string> s8 = {"T", "Z", "N", "S"};
    deque<string> s9 = {"M", "S", "D", "J", "R", "Q", "H", "N"};

    // reverse because I entered opposite
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    reverse(s4.begin(), s4.end());
    reverse(s5.begin(), s5.end());
    reverse(s6.begin(), s6.end());
    reverse(s7.begin(), s7.end());
    reverse(s8.begin(), s8.end());
    reverse(s9.begin(), s9.end());


    int lineNumber = 11; // not parsing the initial stacks
    for (int i = 0; i < lineNumber - 1; i++) {
        my_file.ignore(numeric_limits<streamsize>::max(), '\n');
    }



    while(getline(my_file, line)){
        vector<string> parts;

        string delimiter = " ";

        size_t pos = 0;
        string token;
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            parts.push_back(token);
            line.erase(0, pos + delimiter.length());
        }
        parts.push_back(line);


        vector<int> instructions;
        instructions.push_back(stoi(parts[1]));
        instructions.push_back(stoi(parts[3]));
        instructions.push_back(stoi(parts[5]));

        int indextomove = instructions[0];
        int first_stack = instructions[1];
        int second_stack = instructions[2];

        //cout << indextomove << first_stack << second_stack;

        string transfer[indextomove] = {};
        // Moving crates
        for (int i = 0; i < indextomove; i++) {
            switch(first_stack) {
                case 1:
                    transfer[i] = s1.front();
                    s1.pop_front();
                    break;
                case 2:
                    transfer[i] = s2.front();
                    s2.pop_front();
                    break;
                case 3:
                    transfer[i] = s3.front();
                    s3.pop_front();
                    break;
                case 4:
                    transfer[i] = s4.front();
                    s4.pop_front();
                    break;
                case 5:
                    transfer[i] = s5.front();
                    s5.pop_front();
                    break;
                case 6:
                    transfer[i] = s6.front();
                    s6.pop_front();
                    break;
                case 7:
                    transfer[i] = s7.front();
                    s7.pop_front();
                    break;
                case 8:
                    transfer[i] = s8.front();
                    s8.pop_front();
                    break;
                case 9:
                    transfer[i] = s9.front();
                    s9.pop_front();
                    break;
            }
        }

        for (int i = indextomove - 1; i > -1; i--) {
            // cout << transfer << endl;
            switch(second_stack) {
                case 1:
                    s1.push_front(transfer[i]);
                    break;
                case 2:
                    s2.push_front(transfer[i]);
                    break;
                case 3:
                    s3.push_front(transfer[i]);
                    break;
                case 4:
                    s4.push_front(transfer[i]);
                    break;
                case 5:
                    s5.push_front(transfer[i]);
                    break;
                case 6:
                    s6.push_front(transfer[i]);
                    break;
                case 7:
                    s7.push_front(transfer[i]);
                    break;
                case 8:
                    s8.push_front(transfer[i]);
                    break;
                case 9:
                    s9.push_front(transfer[i]);
                    break;
            }
        }



    }





    my_file.close();
    cout << s1.front() << s2.front() << s3.front() << s4.front() << s5.front() << s6.front() << s7.front() << s8.front() << s9.front() << endl;





    return 0;
}
