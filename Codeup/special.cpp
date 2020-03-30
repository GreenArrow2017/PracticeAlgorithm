//
// Created by GreenArrow on 2020/2/8.
//

#include <iostream>

using namespace std;

int main() {
    string s;
    long long results[100010];
    int index = 0;
    while (getline(cin, s)) {
        string s1 = "", s2 = "";
        bool flag = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                flag = true;
                continue;
            }
            if (!flag) {
                s1 += s[i];
            } else {
                s2 += s[i];
            }
        }

        long long result = 0;

        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); ++j) {
                result += ((s1[i] - '0') * (s2[j] - '0'));
            }
        }
        results[index++] = result;
        cout << result << endl;
    }
//
//    for (int k = 0; k < index; ++k) {
//        cout << results[k] << endl;
//    }
}