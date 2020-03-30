//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int getnumber(string s) {
    int sum = 0;
    for (char c : s) {
        sum = sum * 10 + (c - '0');
    }
    return sum;
}

int main() {
    string A, DA, B, DB;
    while (cin >> A >> DA >> B >> DB) {
        string sa = "", sb = "";
        for (char c: A) {
            if (c == DA[0]) {
                sa += c;
            }
        }
        for (char c : B) {
            if (c == DB[0]) {
                sb += c;
            }
        }
        cout << getnumber(sa) + getnumber(sb) << endl;
    }
}

