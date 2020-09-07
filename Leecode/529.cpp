//
// Created by GreenArrow on 2020/7/29.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:


    int maps[60][60] = {0};
    int direction[8][2] = {{0,  1},
                           {0,  -1},
                           {1,  0},
                           {-1, 0},
                           {1,  1},
                           {1,  -1},
                           {-1, 1},
                           {-1, -1}};

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {


        int nRow = board.size();
        int nColumn = board[0].size();

        int x = click[0], y = click[1];

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }

        bfs(x, y, nRow, nColumn, board);

        return board;

    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    void bfs(int x, int y, int nRow, int nColumn, vector<vector<char>> &board) {
        queue<pair<int, int>> q;
        q.push({x, y});
        board[x][y] = 'B';
        while (!q.empty()) {
            x = q.front().first, y = q.front().second;
            q.pop();
            int mNumber = 0;
            for (int i = 0; i < 8; i++) {
                int x_next = x + direction[i][0], y_next = y + direction[i][1];
                if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn && board[x_next][y_next] == 'M') {
                    mNumber++;
                }
            }
            if (mNumber == 0) {
                for (int i = 0; i < 8; i++) {
                    int x_next = x + direction[i][0], y_next = y + direction[i][1];
                    if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn &&
                        board[x_next][y_next] == 'E') {
                        board[x_next][y_next] = 'B';
                        q.push({x_next, y_next});
                    }
                }
            } else {
                board[x][y] = mNumber + '0';
            }
        }
    }

};

int main() {
    Solution solution;
    vector<vector<char>> test = {{'B', 'B', 'B', 'B', 'B', 'B', '1', 'E'},
                                 {'B', '1', '1', '1', 'B', 'B', '1', 'M'},
                                 {'1', '2', 'M', '1', 'B', 'B', '1', '1'},
                                 {'M', '2', '1', '1', 'B', 'B', 'B', 'B'},
                                 {'1', '1', 'B', 'B', 'B', 'B', 'B', 'B'},
                                 {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
                                 {'B', '1', '2', '2', '1', 'B', 'B', 'B'},
                                 {'B', '1', 'M', 'M', '1', 'B', 'B', 'B'}
    };
    vector<int> click = {0, 7};
    vector<vector<char>> test1 = {{'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'}};

    vector<int> click1 = {3, 0};
    solution.updateBoard(test1, click1);
}
