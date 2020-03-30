//
// Created by GreenArrow on 2020/2/12.
//

#include <iostream>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        bool flag = true;
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}