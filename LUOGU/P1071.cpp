//
// Created by GreenArrow on 2020/3/2.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    int characters[26] = {0};
    map<char, char> s_original;
    string s;
    string original;
    string analyse;
    getline(cin, s);
    getline(cin, original);
    getline(cin, analyse);
    if (original.length() < 26) {
        cout << "Failed" << endl;
        return 0;
    }
    if (original.length() != s.length()) {
        cout << "Failed" << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); ++i) {
        if (!s_original[s[i]] || s_original[s[i]] == original[i]) {
            characters[original[i] - 'A'] = 1;
            s_original[s[i]] = original[i];
        } else {
            cout << "Failed" << endl;
            return 0;
        }
    }

    for (int j = 0; j < 26; ++j) {
        if (characters[j] == 0) {
            cout << "Failed" << endl;
            return 0;
        }
    }

    for (int k = 0; k < analyse.length(); ++k) {
        if(s_original[analyse[k]]){
            cout << s_original[analyse[k]];
        }
    }
}