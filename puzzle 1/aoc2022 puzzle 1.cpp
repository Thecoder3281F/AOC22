#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;


int main(){

    string line;
    vector<string> v;

    vector<vector<string>> v2;

    vector<string> temp_v;
    vector<string> temp_v_2;


    vector<vector<int>> v3;
    vector<int> temp_v_3;

    vector<int> temp_v_4;




    ifstream my_file("./input.txt");



    while(getline(my_file, line)){
        if (line.empty()) {
            v.push_back(""); // use empty string to separate the elves
        } else {
            v.push_back(line);
        }

    }

    my_file.close();


    // separate each elf's calorie values into their own vectors and add all the individual elf vectors to one main vector
    for(int i=0; i < v.size(); i++) {

        if (v[i] != "") {
            temp_v.push_back(v[i]);
        } else {
            v2.push_back(temp_v);
            temp_v.clear();
        }
    }
    v2.push_back(temp_v); // for the last element of the input file


    // convert everything from strings to ints
    for (int i=0; i < v2.size(); i++) {
        temp_v_2 = v2[i];
        for (int j=0; j<temp_v_2.size(); j++) {
            temp_v_3.push_back(stoi(temp_v_2[j]));

        }
        v3.push_back(temp_v_3);
        temp_v_3.clear();
    }


    // create vector containing sum of calories for each elf
    vector<int> sum_vector;
    for (int i=0; i < v3.size(); i++) {
        temp_v_4 = v3[i];
        int sum;
        sum = accumulate(temp_v_4.begin(), temp_v_4.end(), 0);
        sum_vector.push_back(sum);
    }


    // part 1 (elf with most calories)
    int maximum_calories = *max_element(sum_vector.begin(), sum_vector.end());
    cout << "The maximum calories is " << maximum_calories << endl;

    // part 2 (top 3 elves)

    sort(sum_vector.begin(), sum_vector.end(), greater<int>());
    cout << "The values of the top 3 elves are " << sum_vector[0] << ", " << sum_vector[1] << " and " << sum_vector[2] << endl; 
    int sum_top_three = sum_vector[0] + sum_vector[1] + sum_vector[2];
    cout << "Sum is " << sum_top_three;


    return 0;
}
