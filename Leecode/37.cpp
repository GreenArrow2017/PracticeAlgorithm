//
// Created by GreenArrow on 2020/9/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int check_row[9][10];
    int check_column[9][10];
    int check_tian[9][10];

    void solveSudoku(vector<vector<char>> &board) {

        int nRow = board.size();
        int nColumn = board[0].size();

        for (int i = 0; i < 9; i++) {
            fill(check_row[i], check_row[i] + 10, 0);
            fill(check_column[i], check_column[i] + 10, 0);
            fill(check_tian[i], check_tian[i] + 10, 0);

        }

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                if (board[i][j] != '.') {
                    int num = char2int(board[i][j]);
                    check_row[i][num]++;
                    check_column[j][num]++;
                    check_tian[getBox(i, j)][num]++;
                }
            }
        }

        cout << Back_BFS(0, 0, board);


    }

    bool Back_BFS(int x, int y, vector<vector<char>> &board) {
        if (board[x][y] == '.') {
            for (int i = 1; i < 10; i++) {
                board[x][y] = char(i + '0');
                check_row[x][i]++;
                check_column[y][i]++;
                check_tian[getBox(x, y)][i]++;
                if (check(x, y)) {

                    if (x == 8 && y == 8) {
                        return true;
                    }

                    int next_x = 0, next_y = 0;
                    if (y != 8) {
                        next_y = y + 1;
                        next_x = x;
                    } else {
                        next_y = 0;
                        next_x = x + 1;
                    }

                    if (Back_BFS(next_x, next_y, board))
                        return true;

                }
                board[x][y] = '.';
                check_row[x][i]--;
                check_column[y][i]--;
                check_tian[getBox(x, y)][i]--;
            }
        } else {
            if (x == 8 && y == 8) {
                return true;
            }
            int next_x, next_y;
            if (y != 8) {
                next_y = y + 1;
                next_x = x;
            } else {
                next_y = 0;
                next_x = x + 1;
            }

            if (Back_BFS(next_x, next_y, board))
                return true;
        }
        return false;
    }


    bool check(int x, int y) {
        for (int i = 1; i < 10; i++) {
            if (check_row[x][i] > 1 || check_column[y][i] > 1 || check_tian[getBox(x, y)][i] > 1) {
                return false;
            }
        }
        return true;
    }

    int char2int(char c) {
        if (c >= '1' && c <= '9') {
            return int(c - '0');
        } else {
            return -1;
        }
    }

    int getBox(int x, int y) {
        int row = x / 3;
        int column = y / 3;
        return row * 3 + column;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> test = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                 {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solution.solveSudoku(test);
}