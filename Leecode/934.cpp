//
// Created by GreenArrow on 2020/9/25.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:

    int x, y;

    int direction[4][2] = {{1,  0},
                           {-1, 0},
                           {0,  1},
                           {0,  -1}};

    int shortestBridge(vector<vector<int>> &A) {
        int nRow = A.size();
        int nColumn = A[0].size();

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                if (A[i][j]) {
                    return dfs_find_source(i, j, nRow, nColumn, A);
                }
            }
        }
        return -1;

    }

    int dfs_find_source(int x, int y, int nRow, int nColumn, vector<vector<int>> &A) {


        queue<pair<pair<int, int>, int>> q;

        dfs(x, y, nRow, nColumn, q, A);


        //BFS
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;

            q.pop();
            for (int i = 0; i < 4; i++) {
                int x_next = x + direction[i][0];
                int y_next = y + direction[i][1];
                if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn && A[x_next][y_next] != 2) {
                    if (A[x_next][y_next] == 0) {
                        A[x_next][y_next] = 2;
                        q.push({{x_next, y_next}, dist + 1});
                    } else if (A[x_next][y_next] == 1) {
                        return dist;
                    }
                }
            }
        }

        return -1;

    }

    void dfs(int x, int y, int nRow, int nColumn, queue<pair<pair<int, int>, int>> &q, vector<vector<int>> &A) {
        A[x][y] = 2;
        q.push({{x, y}, 0});
        for (auto &i : direction) {
            int x_next = x + i[0];
            int y_next = y + i[1];
            if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn && A[x_next][y_next] == 1) {
                dfs(x_next, y_next, nRow, nColumn, q, A);
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> test = {{0, 1, 0},
                                {0, 0, 0},
                                {0, 0, 1}};
    solution.shortestBridge(test);
}

