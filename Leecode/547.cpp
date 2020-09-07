//
// Created by GreenArrow on 2020/8/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> father;

    int findCircleNum(vector<vector<int>> &M) {
        int nRow = M.size();
        int nColumn = M[0].size();
        father.resize(nRow);
        for (int i = 0; i < nRow; i++) {
            father[i] = i;
        }
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {
                if (M[i][j]) {
                    connect(i, j);
                }
            }
        }
        int num = 0;
        for (int i = 0; i < nRow; i++) {
            if(father[i] == i){
                num++;
            }
        }
        return num;
    }

    void connect(int x, int y) {
        int x_fa = find(x);
        int y_fa = find(y);
        if (x_fa != y_fa) {
            father[x_fa] = y_fa;
        }
    }

    int find(int x) {
        while (x != father[x]) {
            x = father[x];
        }
        return x;
    }
};