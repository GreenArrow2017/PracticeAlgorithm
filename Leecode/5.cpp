//
// Created by GreenArrow on 2020/7/25.
//

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class Solution {
public:

    class cordinate {
    public:
        int start;
        int end;
    };

    string longestPalindrome(string s) {

        if (s.length() == 0) {
            return "";
        }

        cordinate store;

        for (int i = 0; i < s.length(); i++) {
            getMax(s, store, i, i);
            getMax(s, store, i, i + 1);
        }

        string str;
        for (int i = store.start; i < store.end + 1; i++) {
            str += s[i];
        }

        return str;

    }

    void getMax(string s, cordinate &store, int start, int end) {
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            start--;
            end++;
        }

        if (end - start - 1 >= store.end - store.start + 1) {
            store.start = start + 1;
            store.end = end - 1;
        }
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
        string s = stringToString(line);

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
