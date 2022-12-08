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
        char opponent_choice = round[0];
        char outcome = round[2]; // third character of string


        if (outcome == 'X') { // loss
            score += 0; // loss
            if (opponent_choice == 'A') { // rock, so to lose choose scissors
                score += 3;
            } else if (opponent_choice == 'B') { // paper, so to lose choose rock
                score += 1;
            } else if (opponent_choice == 'C') { // scissors, so to lose choose paper
                score += 2;
            }
        } else if (outcome == 'Y') { // draw
            score += 3; // draw
            if (opponent_choice == 'A') { // rock, so to draw choose rock
                score += 1;
            } else if (opponent_choice == 'B') { // paper, so to draw choose paper
                score += 2;
            } else if (opponent_choice == 'C') { // scissors, so to draw choose scissors
                score += 3;
            }
        } else if (outcome == 'Z') { // win
            score += 6; // win
            if (opponent_choice == 'A') { // rock, so to win choose paper
                score += 2;
            } else if (opponent_choice == 'B') { // paper, so to win choose scissors
                score += 3;
            } else if (opponent_choice == 'C') { // scissors, so to win choose rock
                score += 1;
            }
        }
    }

    cout << "The total score is: " << score << endl;
}
