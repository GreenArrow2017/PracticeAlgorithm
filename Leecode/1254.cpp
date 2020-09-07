//
// Created by GreenArrow on 2020/8/11.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    int direction[4][2] = {{0,  1},
                           {0,  -1},
                           {1,  0},
                           {-1, 0}};

    int closedIsland(vector<vector<int>> &grid) {
        int nRow = grid.size();
        int nColumn = grid[0].size();


        for (int i = 0; i < nRow; i++) {

            if (!grid[i][nColumn - 1]) {
                dfs(i, nColumn - 1, nRow, nColumn, grid);
            }

            if (!grid[i][0]) {
                dfs(i, 0, nRow, nColumn, grid);
            }

        }

        for (int i = 0; i < nColumn; i++) {
            if (!grid[0][i]) {
                dfs(0, i, nRow, nColumn, grid);
            }
            if (!grid[nRow - 1][i]) {
                dfs(nRow - 1, i, nRow, nColumn, grid);
            }
        }

        int count = 0;

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                if (!grid[i][j]) {
                    count++;
                    dfs(i, j, nRow, nColumn, grid);
                }
            }
        }

        return count;
    }

    void dfs(int x, int y, int nRow, int nColumn, vector<vector<int>> &grid) {
        grid[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int x_next = x + direction[i][0], y_next = y + direction[i][1];
            if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn && !grid[x_next][y_next]) {
                dfs(x_next, y_next, nRow, nColumn, grid);
            }
        }
    }
};