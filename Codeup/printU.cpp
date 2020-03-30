//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

//hell owo rld!
int main() {
    string s;
    while (cin >> s) {
        int len = s.length();
        int n1 = (len + 2) / 3;
        int n3 = len - n1 * 2;
        int left = 0;
        int right = len - 1;
        for (int i = 0; i < n1 - 1; ++i) {
            cout << s[left];
            for (int j = 0; j < n3; ++j) {
                cout << " ";
            }
            cout << s[right];
            left++, right--;
            cout << endl;
        }
        for (int k = left; k <= left + n3 + 1; ++k) {
            cout << s[k];
        }
        cout << endl;
    }
}