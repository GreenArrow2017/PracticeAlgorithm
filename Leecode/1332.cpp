//
// Created by GreenArrow on 2020/7/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {

        if (s == "") {
            return 0;
        }

        if(isPalid(s)){
            return 1;
        }

        return 2;

    }

    bool isPalid(string s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};