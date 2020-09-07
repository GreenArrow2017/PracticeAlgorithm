//
// Created by GreenArrow on 2020/7/27.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:

    int x_end = 0;
    int y_end = 0;
    int count_road = 0;
    int result = 0;
    int direction[3][2] = {
            {-1, 0},
            {0,  -1},
            {-1, -1}
    };

    vector<int> pathsWithMaxScore(vector<string> &board) {

        vector<int> return_type;

        if (!board.size()) {

            return_type.push_back(0);
            return_type.push_back(0);
        }

        int nRow = board.size();
        int nColumn = board[0].length();

        int x_begnning = nRow - 1;
        int y_begnning = nColumn - 1;

        dfs(x_begnning, y_begnning, nRow, nColumn, board, 0);

        return_type.push_back(result);
        return_type.push_back(count_road);

        return return_type;
    }

    void dfs(int x, int y, int nRow, int nColumn, vector<string> board, int sum) {
        if (x == x_end && y == y_end) {
            if (sum > result) {
                result = sum;
                count_road = 1;
            } else if (sum == result) {
                count_road++;
            }
            return;
        }

        for (int i = 0; i < 3; i++) {
            int x_next = x + direction[i][0], y_next = y + direction[i][1];
            if (x_next >= 0 && x_next < nRow &&
                y_next >= 0 && y_next < nColumn &&
                board[x_next][y_next] != 'X') {
                if (board[x_next][y_next] == 'E')
                    dfs(x_next, y_next, nRow, nColumn, board, sum);
                else if (board[x_next][y_next] != 'E')
                    dfs(x_next, y_next, nRow, nColumn, board, sum + (board[x_next][y_next] - '0'));
            }
        }

    }
};