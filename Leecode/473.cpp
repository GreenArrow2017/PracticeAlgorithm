//
// Created by GreenArrow on 2020/8/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> results;

    bool makesquare(vector<int> &nums) {

        if (!nums.size()) {
            return false;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int large = sum / 4;

        results.assign(4, 0);

        sort(nums.rbegin(), nums.rend());

        return dfs(0, large, nums, results);
    }

    bool dfs(int index, int large, vector<int> &nums, vector<int> &result) {
        if (index >= nums.size()) {
            for (int n : result) {
                if (n != large) {
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (result[i] + nums[index] > large) {
                continue;
            }
            result[i] += nums[index];
            if (dfs(index + 1, large, nums, result)) {
                return true;
            }
            result[i] -= nums[index];
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> test = {5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3};
    solution.makesquare(test);
}