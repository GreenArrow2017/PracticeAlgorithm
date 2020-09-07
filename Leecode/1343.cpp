//
// Created by GreenArrow on 2020/7/22.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {

        return getCounts(arr, k, threshold);

    }

    int getCounts(vector<int> arr, int k, int threshold) {
        int sums = 0;
        int counts = 0;
        int l, r = 0;
        l = 0;
        r = l + k - 1;
        for (int i = l; i <= r; i++) {
            sums += arr[i];
        }
        if (sums >= k * threshold) {
            counts++;
        }
        while (r < arr.size()-1) {
            sums -= arr[r - k + 1];
            sums += arr[++r];
            if (sums >= k * threshold) {
                counts++;
            }
        }
        return counts;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int threshold = stringToInteger(line);

        int ret = Solution().numOfSubarrays(arr, k, threshold);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
