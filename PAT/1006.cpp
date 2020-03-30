//
// Created by GreenArrow on 2020/2/5.
//

#include <iostream>
#include <algorithm>

using namespace std;

void print(string s) {
    if (s.length() == 3) {
        int n = (s[0] - '0');
        for (int i = 0; i < n; ++i) {
            cout << "B";
        }
        int m = (s[1] - '0');
        for (int i = 0; i < m; ++i) {
            cout << "S";
        }
        int k = (s[2] - '0');
        for (int i = 0; i < k; ++i) {
            cout << i+1;
        }
    } else if (s.length() == 2) {
        int n = (s[0] - '0');
        for (int i = 0; i < n; ++i) {
            cout << "S";
        }
        int m = (s[1] - '0');
        for (int i = 0; i < m; ++i) {
            cout << i+1;
        }
    } else if (s.length() == 1) {
        int m = (s[0] - '0');
        for (int i = 0; i < m; ++i) {
            cout << i+1;
        }
    }

}

int main() {
    string s;
    cin >> s;
    print(s);
    return 0;
}
