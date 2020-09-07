//
// Created by GreenArrow on 2020/7/29.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    class cordination {
    public:
        int x;
        int y;

        cordination(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };

    void solve(vector<vector<char>> &board) {

        if(board.size() == 0){
            return;
        }

        int nRow = board.size();
        int nColumn = board[0].size();
        for (int i = 0; i < nRow; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, nRow, nColumn, board);
            }
            if (board[i][nColumn - 1] == 'O') {
                dfs(i, nColumn - 1, nRow, nColumn, board);
            }
        }
        for (int i = 0; i < nColumn; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i, nRow, nColumn, board);
            }
            if (board[nRow - 1][i] == 'O') {
                dfs(nRow - 1, i, nRow, nColumn, board);
            }
        }

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }

    }

    void dfs(int x, int y, int nRow, int nColumn, vector<vector<char>> &board) {
        if (x >= 0 && x < nRow && y >= 0 && y < nColumn && board[x][y] == 'O') {
            board[x][y] = '#';
            dfs(x + 1, y, nRow, nColumn, board);
            dfs(x - 1, y, nRow, nColumn, board);
            dfs(x, y + 1, nRow, nColumn, board);
            dfs(x, y - 1, nRow, nColumn, board);
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> test = {{'X', 'X', 'X', 'X'},
                                 {'X', 'O', 'O', 'X'},
                                 {'X', 'X', 'O', 'X'},
                                 {'X', 'O', 'X', 'X'}};
    solution.solve(test);
    for (vector<char> v : test) {
        for (char c : v) {
            cout << c << " ";
        }
        cout << endl;
    }
}