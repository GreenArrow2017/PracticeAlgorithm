//
// Created by GreenArrow on 2020/3/15.
//
#include <iostream>
#include <algorithm>

using namespace std;

int cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    sort(s, s + n, cmp);
    string result;
    for (int i = 0; i < n; ++i) {
        result += s[i];
    }

    int index_ = 0;
    for (int j = 0; j < result.length(); ++j) {
        if (result[j] == '0') {
            index_++;
        } else
            break;
    }
    if (index_ == result.length()) {
        cout << "0";
        return 0;
    }
    result = result.substr(index_, result.length() - index_);
    cout << result;
}