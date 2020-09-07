//
// Created by GreenArrow on 2020/7/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;


class Solution {
public:
    int movesToMakeZigzag(vector<int> &nums) {

        int oddStep = 0;
        int evenStep = 0;


        for (int i = 0; i < nums.size(); i++) {
            if (i % 2) {
                int gap = 0;
                if (i > 0) {
                    gap = nums[i] - nums[i - 1] + 1 >= gap ? nums[i] - nums[i - 1] + 1 : gap;
                }
                if (i + 1 < nums.size()) {
                    gap = nums[i] - nums[i + 1] + 1 >= gap ? nums[i] - nums[i + 1] + 1 : gap;

                }
                oddStep += gap;
            } else {
                int gap = 0;
                if (i > 0) {
                    gap = nums[i] - nums[i - 1] + 1 >= gap ? nums[i] - nums[i - 1] + 1 : gap;
                }
                if (i + 1 < nums.size()) {
                    gap = nums[i] - nums[i + 1] + 1 >= gap ? nums[i] - nums[i + 1] + 1 : gap;

                }
                evenStep += gap;
            }
        }

        return oddStep >= evenStep ? evenStep : oddStep;


    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().movesToMakeZigzag(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}