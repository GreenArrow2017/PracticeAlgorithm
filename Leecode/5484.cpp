//
// Created by GreenArrow on 2020/8/9.
//

#include <iostream>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {

        string str = "0";

        n--;

        while (n--) {
            str = str + '1' + revert(invert(str));
        }

        return str[k - 1];

    }

    string invert(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0')
                str[i] = '1';
            else
                str[i] = '0';
        }
        return str;
    }

    string revert(string str) {
        for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        return str;
    }


};