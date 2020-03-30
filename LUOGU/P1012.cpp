//
// Created by GreenArrow on 2020/3/2.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    int length = (a.length() < b.length() ? a.length() : b.length());
    for (int i = 0; i < length; ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }

    if (a.length() != b.length()) {
        if (a.length() > b.length()) {
            return a[length] < a[length - 1];
        } else if (a.length() < b.length()) {
            return b[length] < b[length - 1];
        }
    }

    //return a + b < b + a;
}

int main() {
    vector<string> numbers;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        numbers.push_back(s);
    }
    sort(numbers.rbegin(), numbers.rend(), cmp);
    for (int j = 0; j < numbers.size(); ++j) {
        cout << numbers[j];
    }

}