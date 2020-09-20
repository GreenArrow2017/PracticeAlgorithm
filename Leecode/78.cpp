//
// Created by GreenArrow on 2020/9/20.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    map<int, bool> isExist;
    vector<bool> visited;
    vector<vector<int>> results;

    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size();
        visited.resize(n+1);

        vector<int> result;

        generator(0, nums, result);

        return results;
    }

    void generator(int cur_index, vector<int> &nums, vector<int> &result) {
        if (cur_index == nums.size()) {
            results.push_back(result);
            return;
        }
        result.push_back(nums[cur_index]);
        generator(cur_index+1, nums, result);
        result.pop_back();
        generator(cur_index+1, nums, result);

    }


};


