//
// Created by GreenArrow on 2020/8/9.
//

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class Solution {
public:
    string makeGood(string s) {

        string result;
        string pre = s;

        result = judge(pre);

        while (result != pre) {
            pre = result;
            result = judge(result);
        }

        return result;

    }

    string judge(string s) {
        if (s == "" || s.length() == 0) {
            return s;
        }
        for (int i = 0; i < s.length() - 1; i++) {

            if ((s[i] - s[i + 1] == 'a' - 'A' || s[i] - s[i + 1] == 'A' - 'a') && 0 <= i <= s.length() - 1) {
                s[i] = ' ';
                s[i + 1] = ' ';
            }

        }

        string result;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                result += s[i];
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.makeGood("Pp");
}