#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main() {
    vector<string> strategy_guide;
    string line;

    int score;

    ifstream my_file("./input.txt");



    while(getline(my_file, line)){
        strategy_guide.push_back(line);
    }

    my_file.close();

    for (int i=0; i < strategy_guide.size(); i++) {

        string round = strategy_guide[i];
        char choice = round[2]; // third character of string


        if (choice == 'X') {
            score += 1;
        } else if (choice == 'Y') {
            score += 2;
        } else if (choice == 'Z') {
            score += 3;
        }

        if (round == "A Y" || round == "B Z" || round == "C X") {
            score += 6;
        } else if (round == "A X" || round == "B Y" || round == "C Z") {
            score += 3;
        }

        // loss means no score added
    }

    cout << "The total score is: " << score << endl;
}
