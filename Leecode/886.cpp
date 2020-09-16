//
// Created by GreenArrow on 2020/9/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> Graph;

    //red : 1, blue : -1, none : 0

    vector<int> colors;

    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        Graph.resize(N);
        colors.resize(N);
        fill(colors.begin(), colors.end(), 0);
        for (int i = 0; i < dislikes.size(); i++) {
            Graph[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            Graph[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }

        for (int i = 0; i < N; i++) {
            if (colors[i] == 0) {
                colors[i] = 1;
                if (!fillColor(i)) {
                    return false;
                }
            }
        }

        return true;

    }

    bool fillColor(int v) {
        for (int i = 0; i < Graph[v].size(); i++) {
            int w = Graph[v][i];
            if (colors[w] == 0) {
                colors[w] = -1 * colors[v];
                fillColor(w);
            } else if (colors[w] * colors[v] == 1) {
                return false;
            }
        }

        return true;

    }


};

int main() {
    Solution solution;
    vector<vector<int>> test = {{1, 2},
                                {1, 3},
                                {2, 4}};
    int N = 4;
    solution.possibleBipartition(4, test);
}