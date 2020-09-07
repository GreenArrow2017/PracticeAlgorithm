//
// Created by GreenArrow on 2020/7/21.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long sum = 0;
        bool beginning = true;
        long sign = +1;
        for (char c : str) {
            if (beginning && c == ' ') {
                continue;
            } else if (beginning && (c == '+' || c == '-')) {
                if (c == '+') {
                    sign = 1;
                } else {
                    sign = -1;
                }
                beginning = false;
            } else if(beginning && isDigit(c)){
                sum = sum * 10 + (c - '0');
                if(sign * sum >= INT_MAX || sign * sum <= INT_MIN){
                    return normolization(sign * sum);
                }
                beginning = false;
            } else if(!beginning && isDigit(c)){
                sum = sum * 10 + (c - '0');
                if(sign * sum >= INT_MAX || sign * sum <= INT_MIN){
                    return normolization(sign * sum);
                }
                beginning = false;
            } else{
                return normolization(sign * sum);
            }
        }
        return normolization(sign * sum);
    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    int normolization(long long result){
        if(result <= INT_MIN){
            return INT_MIN;
        }
        if(result >= INT_MAX){
            return INT_MAX;
        }
        return result;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"');
                    break;
                case '/' :
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case 'b' :
                    result.push_back('\b');
                    break;
                case 'f' :
                    result.push_back('\f');
                    break;
                case 'r' :
                    result.push_back('\r');
                    break;
                case 'n' :
                    result.push_back('\n');
                    break;
                case 't' :
                    result.push_back('\t');
                    break;
                default:
                    break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}