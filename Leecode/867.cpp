//
// Created by GreenArrow on 2020/9/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        int nRow = A.size();
        int nColumn = A[0].size();
        vector<vector<int>> results;
        results.resize(nColumn);
        for (int i = 0; i < nColumn; i++) {
            for (int j = 0; j < nRow; j++) {
                results[i].push_back(0);
            }
        }

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                results[j][i] = A[i][j];
            }
        }


        return results;
    }
};