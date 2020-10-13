//
// Created by GreenArrow on 2020/10/13.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCount = 0;
    int maxNumber = INT_MIN;

    int getWinner(vector<int> &arr, int k) {
        if (k == 1) {
            return max(arr[0], arr[1]);
        }
        int preMax = max(arr[1], arr[0]);
        maxCount = 1;
        for (int i = 2; i < arr.size(); i++) {
            if (preMax > arr[i]) {
                maxCount++;
            } else {
                preMax = arr[i];
                maxCount = 1;
            }
            if (maxCount == k) {
                return preMax;
            }
        }
        return preMax;
    }
};
