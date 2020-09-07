//
// Created by GreenArrow on 2020/7/27.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        long result = 0;
        int sign = 1;
        if (x < 0)
            sign = -1;
        string str;
        x = abs(x);
        while (x >= 10) {
            str += ((x % 10)+'0');
            x /= 10;
        }
        str += (x + '0');

        for (char c : str) {
            result = result * 10 + (c - '0');
            if (result * sign >= pow(2, 31) - 1) {
                return 0;
            }
            if (result * sign <= -pow(2, 31)) {
                return 0;
            }
        }
        return result * sign;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}