#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;



bool contains(vector<int> v1, vector<int> v2) {

    int counter = 0;


    for (int i = 0; i < v2.size(); i++) {
        for (int j = 0; j < v1.size(); j++) {
            if (v2[i] == v1[j]) {
                counter++;
            }
        }
    }

    if (counter == v2.size()) {
        return true;
    } else {
        return false;
    }
}


bool overlaps(vector<int> v1, vector<int> v2) {

    auto it = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
    if (it != v1.end()) { // if there is a common element
        return true;
    } else {
        return false;
    }
}


int main() {
    string line;
    vector<vector<string>> ranges;
    int contains_counter = 0; // contained pairs
    int overlaps_counter = 0; // overlapped pairs


    ifstream my_file("./input.txt");



    while(getline(my_file, line)){
        string s = line;
        vector<string> v;

        size_t pos = s.find(',');
        string first = s.substr(0, pos);
        string second = s.substr(pos + 1);

        v.push_back(first);
        v.push_back(second);

        ranges.push_back(v);
        v.clear();
    }

    my_file.close();



    vector<int> v2;

    for (int i = 0; i < ranges.size(); i++) {
        vector<string> temp_v = ranges[i];
        vector<int> v1; // first range
        vector<int> v2; // second range

        // Find the position of the hyphen
        string s1 = temp_v[0];
        string s2 = temp_v[1];

        size_t pos_1 = s1.find('-');
        size_t pos_2 = s2.find('-');


        // Get the starting and ending values
        int start_1 = stoi(s1.substr(0, pos_1));
        int end_1 = stoi(s1.substr(pos_1 + 1));
        int start_2 = stoi(s2.substr(0, pos_2));
        int end_2 = stoi(s2.substr(pos_2 + 1));

        // Add the values from start to end (inclusive) to the vector
        for (int i = start_1; i <= end_1; ++i) {
            v1.push_back(i);
        }

        for (int i = start_2; i <= end_2; ++i) {
            v2.push_back(i);
        }





        if (contains(v1, v2) || contains(v2, v1)) { // if the first range contains the second, or vice versa
            contains_counter++;
        }

        if (overlaps(v1, v2)) {
            overlaps_counter++;
        }


    }

    cout << "The amount of rows where one range fully contains the other: " << contains_counter << endl;
    cout << "The amount of rows where the ranges overlap: " << overlaps_counter << endl;
    return 0;
}
