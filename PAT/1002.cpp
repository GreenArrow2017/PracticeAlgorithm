//
// Created by GreenArrow on 2020/2/5.
//
#include <iostream>

using namespace std;

string match(int num) {
    string s = "";
    switch (num) {
        case 0:
            s = "gnil";
            break;
        case 1:
            s = "iy";
            break;
        case 2:
            s = "re";
            break;
        case 3:
            s = "nas";
            break;
        case 4:
            s = "is";
            break;
        case 5:
            s = "uw";
            break;
        case 6:
            s = "uil";
            break;
        case 7:
            s = "iq";
            break;
        case 8:
            s = "ab";
            break;
        case 9:
            s = "uij";
            break;
    }
    return s;
}

string ChangeN(int num) {
    string s = "";
    while (num / 10 != 0) {
        int n = num % 10;
        num /= 10;
        s += match(n);
        s += " ";
    }
    s += match(num);
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
        char temp;
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    int num = 0;
    for (char c:s) {
        num += (c - '0');
    }
    cout << ChangeN(num);
}

