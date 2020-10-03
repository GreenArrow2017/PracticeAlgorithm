//
// Created by GreenArrow on 2020/10/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int direction[4][2] = {{0,  1},
                           {0,  -1},
                           {1,  0},
                           {-1, 0}};

    vector<bool> visited;

    bool exist(vector<vector<char>> &board, string word) {
        int nRow = board.size();
        int nColumn = board[0].size();
        visited.resize(nRow * nColumn);

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                if (board[i][j] == word[0]) {
                    if (backtrackWords(board, word, 0, i, j, nRow, nColumn)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool backtrackWords(vector<vector<char>> &board, string &word, int index, int x, int y, int nRow, int nColumn) {
        if (index == word.size()-1) {
            return true;
        }

        visited[x * nColumn + y] = true;

        for (int i = 0; i < 4; i++) {
            int next_x = x + direction[i][0];
            int next_y = y + direction[i][1];
            if (next_x >= 0 && next_x < nRow && next_y >= 0 && !visited[next_x * nColumn + next_y] && next_y < nColumn &&
                board[next_x][next_y] == word[index+1]) {
                if (backtrackWords(board, word, index + 1, next_x, next_y, nRow, nColumn)) {
                    return true;
                }
            }
        }

        visited[x * nColumn + y] = false;

        return false;

    }
};

int main() {
    Solution solution;
    vector<vector<char>> test = {{'A', 'B'}

                                };
    string words = "BA";

    cout << solution.exist(test, words);
}