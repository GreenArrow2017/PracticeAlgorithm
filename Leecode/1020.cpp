//
// Created by GreenArrow on 2020/8/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    int direction[4][2] = {{0,  1},
                           {0,  -1},
                           {1,  0},
                           {-1, 0}};

    int numEnclaves(vector<vector<int>> &A) {
        queue<pair<int, int>> q;
        int nRow = A.size();
        int nColumn = A[0].size();
        for (int i = 0; i < nRow; i++) {
            if (A[i][0]) {
                q.push({i, 0});
            }
            if (A[i][nColumn - 1]) {
                q.push({i, nColumn - 1});
            }
        }

        for (int i = 0; i < nColumn; i++) {
            if (A[0][i]) {
                q.push({0, i});
            }
            if (A[nRow - 1][i]) {
                q.push({nRow - 1, i});
            }
        }

        while (!q.empty()) {
            DFS(q.front().first, q.front().second, nRow, nColumn, A);
            q.pop();
        }

        int sum = 0;

        for(int i = 0;i < nRow;i++){
            for(int j = 0;j < nColumn;j++){
                sum += A[i][j];
            }
        }
        return sum;
    }

    void DFS(int x, int y, int nRow, int nColumn, vector<vector<int>> &Graph) {
        if (!Graph[x][y]) {
            return;
        }
        Graph[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int x_next = x + direction[i][0];
            int y_next = y + direction[i][1];
            if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn && Graph[x_next][y_next]) {
                DFS(x_next, y_next, nRow, nColumn, Graph);
            }
        }
    }
};