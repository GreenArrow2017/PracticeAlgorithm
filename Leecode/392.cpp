//
// Created by GreenArrow on 2020/7/27.
//

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int index_s = 0, index_t = 0;

        while (index_s < s.length() && index_t < t.length()) {
            if (s[index_s] == t[index_t]) {
                index_s++;
                index_t++;
            } else {
                index_t++;
            }
        }

        if(index_s >= s.length()){
            return true;
        } else{
            return false;
        }

    }
};
