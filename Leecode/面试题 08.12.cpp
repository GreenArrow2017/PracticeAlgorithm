//
// Created by GreenArrow on 2020/9/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> count_column;
    vector<int> count_diag_left;
    vector<int> count_diag_right;
    vector<vector<string>> results;

    vector<vector<string>> solveNQueens(int n) {

        count_column.resize(n);
        count_diag_left.resize(10000);
        count_diag_right.resize(10000);

        vector<string> result;
        result.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i] += '.';
            }
        }

        eightQueue(0, n, result);

        return results;

    }

    bool check(int x, int y, int n) {
        if (count_column[y] || count_diag_left[x + y] || count_diag_right[x - y + n]) {
            return false;
        }
        return true;
    }

    void eightQueue(int x, int n, vector<string> result) {
        if (x == n) {
            results.push_back(result);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (check(x, i, n)) {
                count_column[i] = true;
                count_diag_left[x + i] = true;
                count_diag_right[x - i + n] = true;
                result[x][i] = 'Q';
                eightQueue(x + 1, n, result);
                count_column[i] = false;
                count_diag_left[x + i] = false;
                count_diag_right[x - i + n] = false;
                result[x][i] = '.';
            }
        }
    }
};