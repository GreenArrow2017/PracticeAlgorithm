//
// Created by GreenArrow on 2020/8/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {

        vector<pair<int, int>> results;
        int nRow = mat.size();
        int nColumn = mat[0].size();
        for (int i = 0; i < nRow; i++) {
            int sum = 0;
            for (int j = 0; j < nColumn; j++) {
                if (mat[i][j]) {
                    sum++;
                }
            }
            results.push_back({sum, i});
        }
        sort(results.begin(), results.end());
        vector<int> n;
        for(int i = 0;i < k;i++){
            n.push_back(results[i].second);
        }
        return n;
    }
};
