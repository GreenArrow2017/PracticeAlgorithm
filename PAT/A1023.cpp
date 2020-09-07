//
// Created by GreenArrow on 2020/4/9.
//
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

#define MAX 10
using namespace std;

char int2string(int num) {
    stringstream ss;
    ss << num;
    return ss.str()[0];
}

void reverse(string &s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

string doubleNumber(string s) {
    int addC = 0;
    string S = s;
    reverse(S);
    for (int i = 0; i < S.size(); ++i) {
        char c = S[i];
        int number = (c - '0') * 2 + addC;
        S[i] = int2string(number % 10);
        addC = number / 10;
    }

    if (addC != 0) {
        S += int2string(addC);
    }
    reverse(S);
    return S;
}

int main() {
    int array[MAX];
    int next[MAX];
    fill(array, array + MAX, 0);
    fill(next, next + MAX, 0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        int num = (s[i] - '0');
        array[num]++;
    }


    string result = doubleNumber(s);

    for (int j = 0; j < result.size(); ++j) {
        next[result[j] - '0']++;
    }

    for (int k = 0; k < 10; ++k) {
        if (array[k] != next[k]) {
            cout << "No" << endl;
            cout << result;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << result;

}

