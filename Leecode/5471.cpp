//
// Created by GreenArrow on 2020/8/9.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int> &nums, int target) {

        int MAX = INT_MIN;

        int result = 0;

        for (int i = 0; i < target; i++) {
            result += nums[i];
        }
        MAX = max(MAX, result);

        int left = 0, right = target - 1;

    }
};