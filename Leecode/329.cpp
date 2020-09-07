//
// Created by GreenArrow on 2020/7/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000
using namespace std;


int **memory;
int direction[4][2] = {
        {0,  1},
        {0,  -1},
        {1,  0},
        {-1, 0}
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {

        if (matrix.size() == 0) {
            return 0;
        }

        int maxLength = 0;

        int nRow = matrix.size();
        int nColumn = matrix[0].size();

        memory = new int *[nRow];

        for(int i = 0;i < nRow;i++){
            memory[i] = new int[nColumn];
            fill(memory[i], memory[i] + nColumn, 0);
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                maxLength = max(maxLength, dfs(i, j, nRow, nColumn, matrix));
            }
        }

        return maxLength;

    }

    int dfs(int row, int column, int nRow, int nColumn, vector<vector<int>> matrix) {
        if (memory[row][column] != 0) {
            return memory[row][column];
        }
        memory[row][column]++;
        for (auto & i : direction) {
            int newRow = row + i[0];
            int newColumn = column + i[1];
            if (newRow >= 0 && newRow < nRow && newColumn >= 0 && newColumn < nColumn &&
                matrix[row][column] < matrix[newRow][newColumn]) {
                memory[row][column] = max(memory[row][column], dfs(newRow, newColumn, nRow, nColumn, matrix) + 1);
            }
        }
        return memory[row][column];
    }
};
