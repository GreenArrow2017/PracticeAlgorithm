//
// Created by GreenArrow on 2020/7/31.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {

        vector<int> answer(N);
        vector<vector<int>> graph(N);
        for (int i = 0; i < paths.size(); i++) {
            graph[paths[i][0] - 1].push_back(paths[i][1] - 1);
            graph[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }

        for (int i = 0; i < N; i++) {
            if (!answer[i]) {
                for (int j = 1; j <= 4; j++) {
                    bool flag = false;
                    for (int v = 0; v < graph[i].size(); v++) {
                        if (j == answer[graph[i][v]]) {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) {
                        answer[i] = j;
                        break;
                    }
                }
            }
        }

        return answer;

    }
};

int main() {
    Solution solution;
    vector<vector<int>> test = {{1, 2},
                                {3, 4}};
    solution.gardenNoAdj(4, test);
}