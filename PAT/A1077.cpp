//
// Created by GreenArrow on 2020/3/9.
//
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string ss[n];
    int length = INT_MAX;
    for (int i = 0; i < n; ++i) {
        getline(cin, ss[i]);
        reverse(ss[i].begin(), ss[i].end());
        length = ((length > ss[i].length()) ? ss[i].length() : length);
    }

    string result;
    bool flag = false;
    for (int j = 0; j < length; ++j) {

        char c = ss[0][j];
        for (int i = 1; i < n; ++i) {
            if (c != ss[i][j]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
        result += c;
    }

    if (result.empty()) {
        cout << "nai";
        return 0;
    }

    reverse(result.begin(), result.end());

    cout << result;

}