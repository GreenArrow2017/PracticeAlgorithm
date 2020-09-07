//
// Created by GreenArrow on 2020/9/3.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> results;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> result;
        result.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i] += '.';
            }
        }
        vector<pair<int, int>> QueenPosition;
        putQueen(0, n, result, QueenPosition);
        return results;
    }

    void putQueen(int index, int n, vector<string> &result, vector<pair<int, int>> QueenPosition) {
        if (index == n) {
            results.push_back(result);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vertical(index, i, result, QueenPosition) && triangle(index, i, result, QueenPosition)) {
                int x = index;
                int y = i;
                QueenPosition.push_back({x, y});
                result[index][y] = 'Q';
                putQueen(index + 1, n, result, QueenPosition);
                result[index][y] = '.';
                QueenPosition.pop_back();
            }
        }


    }

    bool vertical(int x, int y, vector<string> &result, vector<pair<int, int>> QueenPosition) {
        for (int i = 0; i < QueenPosition.size(); i++) {
            int pre_y = QueenPosition[i].second;
            if (pre_y == y) {
                return false;
            }
        }
        return true;
    }

    bool triangle(int x, int y, vector<string> &result, vector<pair<int, int>> QueenPosition) {
        for (int i = 0; i < QueenPosition.size(); i++) {
            if (QueenPosition[i].first - QueenPosition[i].second == x - y) {
                return false;
            }

            if(QueenPosition[i].first + QueenPosition[i].second == x + y){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    solution.solveNQueens(4);
}