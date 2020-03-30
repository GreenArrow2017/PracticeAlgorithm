//
// Created by GreenArrow on 2020/2/12.
//

#include <iostream>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, j--) {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        cout << s << endl;
    }
}
