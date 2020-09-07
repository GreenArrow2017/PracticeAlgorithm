//
// Created by GreenArrow on 2020/8/30.
//

#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        string word;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == ' '){
                reverse(word);
                result += word;
                result += ' ';
                word = "";
            } else{
                word += s[i];
            }
        }
        reverse(word);
        result += word;

        return result;
    }

    void reverse(string &s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};