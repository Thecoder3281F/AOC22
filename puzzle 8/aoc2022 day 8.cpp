#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int chartoint(char c) {
    return c - '0';
}

int isvisible(vector<string> grid) {
    int trees_visible = 0;
    for (int i = 0; i < grid.size(); i++) {
        if (i == 0 || i == grid.size() - 1) {
            continue;
        } else {
            string current_row = grid[i];

            vector<int> treesonsamerow;

            for (int j = 0; j < current_row.length(); j++) {
                treesonsamerow.push_back(chartoint(current_row[j]));
            }

            for (int k = 0; k < treesonsamerow.size(); k++) {
                if (k == 0 || k == treesonsamerow.size() - 1) {
                    continue;
                } else {
                    int tree_height_current_row = treesonsamerow[k];
                    vector<int> treesonsamecolumn;
                    for (int l = 0; l < grid.size(); l++) {
                        treesonsamecolumn.push_back(chartoint(grid[l][k]));
                    }

                    bool isvisibleleft = true;
                    bool isvisibleup = true;
                    bool isvisibleright = true;
                    bool isvisibledown = true;

                    int tree_height_current_column = treesonsamecolumn[i];

                    for (int m = 0; m < treesonsamerow.size(); m++) {
                        int tree_height_row = treesonsamerow[m];
                        if (tree_height_row >= tree_height_current_row && m != k) {
                            if (m < k) {
                                isvisibleleft = false;
                            } else {
                                isvisibleright = false;
                            }
                            break;
                        }
                    }

                    for (int n = 0; n < treesonsamecolumn.size(); n++) {
                        int tree_height_column = treesonsamecolumn[n];
                        if (tree_height_column >= tree_height_current_column && n != i) {
                            if (n < i) {
                                isvisibleup = false;
                            } else {
                                isvisibledown = false;
                            }
                            break;
                        }
                    }

                    if (isvisibleleft || isvisibleright || isvisibleup || isvisibledown) {
                        trees_visible++;
                    }

                }
            }



        }
    }
    return trees_visible;
}


int main() {
    ifstream my_file("./input.txt");
    vector<string> grid;
    string line;




    while(getline(my_file, line)){
        grid.push_back(line);

    }

    my_file.close();


    int visible = 0;

    int edge_trees = grid.size() * grid[0].length() - (grid.size() - 2) * (grid[0].length() - 2);

    visible += edge_trees;

    cout << visible << endl;
    visible += isvisible(grid);


    cout << visible << endl;

}
