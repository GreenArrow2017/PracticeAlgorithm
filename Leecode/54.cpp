//
// Created by GreenArrow on 2020/8/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> results;
        int nRow = matrix.size();
        int nColumn = matrix[0].size();
        int i = 0, j = 0;
        int number = 0;
        int total = nRow * nColumn;
        bool flag = false;
        int spend_x = 1;
        int spend_y = 1;
        nRow--;
        nColumn--;
        results.push_back(matrix[i][j]);
        int index = 0;
        number++;
        while (number < total) {
            index++;
            if (!flag) {
                for (int k = 0; k < nColumn; ++k) {
                    j += spend_y;
                    results.push_back(matrix[i][j]);
                }
                spend_y *= -1;
                flag = true;
                number += nColumn;
                if (index != 1) {
                    nColumn--;
                }
                continue;
            } else {
                for (int k = 0; k < nRow; k++) {
                    i += spend_x;
                    results.push_back(matrix[i][j]);
                }
                spend_x *= -1;
                flag = false;
                number += nRow;
                nRow--;
            }

        }
        return results;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> test = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };
    vector<int> pr = solution.spiralOrder(test);
    for (int i = 0; i < pr.size(); i++) {
        cout << pr[i] << " ";
    }
}

//[ 1, 2, 3 ],
//[ 4, 5, 6 ],
//[ 7, 8, 9 ]