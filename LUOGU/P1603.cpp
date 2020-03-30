//
// Created by GreenArrow on 2020/3/2.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int alpha2Number(string s) {
    if (s == "one" || s == "a" || s == "another" || s == "first") {
        return 1;
    } else if (s == "two" || s == "both" || s == "second") {
        return 2;
    } else if (s == "three")
        return 3;
    else if (s == "four")
        return 4;
    else if (s == "five")
        return 5;
    else if (s == "six")
        return 6;
    else if (s == "seven")
        return 7;
    else if (s == "eight")
        return 8;
    else if (s == "nine")
        return 9;
    else if (s == "ten")
        return 10;
    else if (s == "eleven")
        return 11;
    else if (s == "twelve")
        return 12;
    else if (s == "thirteen")
        return 13;
    else if (s == "fourteen")
        return 14;
    else if (s == "fifteen")
        return 15;
    else if (s == "sixteen")
        return 16;
    else if (s == "seventeen")
        return 17;
    else if (s == "eighteen")
        return 18;
    else if (s == "nineteen")
        return 19;
    else if (s == "twenty")
        return 20;
    else
        return -1;
}

void spilt(string s, vector<string> &result) {
    string word = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            s[i] = tolower(s[i]);
            word += s[i];
        } else {
            result.push_back(word);
            word = "";
        }
    }
    result.push_back(word);
}

int main() {
    string s;
    getline(cin, s);
    vector<string> results;
    spilt(s, results);
    vector<int> numbers;
    for (int i = 0; i < results.size(); ++i) {
        int num = alpha2Number(results[i]);
        if (num != -1) {
            numbers.push_back((num * num) % 100);
        }
    }
    sort(numbers.begin(), numbers.end());
    bool flag = false;
    for (int j = 0; j < numbers.size(); ++j) {
        if (!flag && numbers[j] != 0) {
            flag = true;
            cout << numbers[j];
        } else
            printf("%02d", numbers[j]);
    }
    if (!flag) {
        cout << 0;
    }
}