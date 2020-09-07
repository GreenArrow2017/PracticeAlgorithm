//
// Created by GreenArrow on 2020/7/22.
//
#include <vector>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:

    string tictactoe(vector<string> &board) {

        int N = board.size();
        vector<int> sum_column(N);
        vector<int> sum_row(N);
        int left_corner = 0;
        int right_corner = 0;
        fill(sum_column.begin(), sum_column.end(), 0);
        fill(sum_row.begin(), sum_row.end(), 0);

        bool empty = false;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {

                if (!empty && board[i][j] == ' ') {
                    empty = true;
                }

                sum_column[i] += board[i][j];
                sum_row[j] += board[i][j];
                if (i == j) {
                    left_corner += board[i][j];
                }
                if (i + j == N - 1) {
                    right_corner += board[i][j];
                }
            }
        }

        for (int k = 0; k < N; ++k) {
            if (sum_column[k] == 'X' * N) {
                return "X";
            } else if (sum_column[k] == 'O' * N) {
                return "O";
            } else if (sum_row[k] == 'X' * N) {
                return "X";
            } else if (sum_row[k] == 'O' * N) {
                return "O";
            } else if (left_corner == 'X' * N) {
                return "X";
            } else if (left_corner == 'O' * N) {
                return "O";
            } else if (right_corner == 'X' * N) {
                return "X";
            } else if (left_corner == 'O' * N) {
                return "O";
            }
        }

        if (empty) {
            return "Pending";
        } else
            return "Draw";
    }

};
