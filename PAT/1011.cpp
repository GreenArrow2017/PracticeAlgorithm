//
// Created by GreenArrow on 2020/2/7.
//

#include <iostream>
#include <stdio.h>
/**
 * 注意数字范围，不过题目是31次方，按照正常
 */
using namespace std;

int main() {
    long long A, B, C;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &A, &B, &C);
        cout << "Case #" << (i + 1) << ": ";
        string s = (A + B > C) ? "true" : "false";
        cout << s << endl;
    }
}