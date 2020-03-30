//
// Created by GreenArrow on 2020/2/8.
//

#include <cstdio>
#include <iostream>

using namespace std;

long long getNumber(string s) {
    int sign = 1;
    int index = 0;
    if (s[0] == '-') {
        sign = -1;
        index++;
    } else {
        sign = 1;
    }

    long long sum = 0;
    for (int i = index; i < s.length(); ++i) {
        sum = sum * 10 + (s[i] - '0');
    }
    return sum * sign;
}

long long calculate(string s) {
    string s1 = "", s2 = "";
    bool flag = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            flag = true;
            continue;
        } else if (s[i] == ',') {
            continue;
        }
        if (!flag) {
            s1 += s[i];
        } else {
            s2 += s[i];
        }

    }
    return getNumber(s1) + getNumber(s2);

}

int main() {
    string s;
    long long arr[100010];
    int index = 0;
    while (getline(cin, s)) {
        string s1, s2;
        arr[index++] = calculate(s);
    }
    for (int i = 0; i < index; i++) {
        cout << arr[i] << endl;
    }
}
