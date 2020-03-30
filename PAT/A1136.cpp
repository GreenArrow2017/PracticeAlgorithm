//
// Created by GreenArrow on 2020/3/7.
//
#include <iostream>
#include <sstream>

using namespace std;

bool isPalindromic(string s) {
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

string add(string a, string b) {
    string c = a;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        c[i] = (a[i] - '0' + b[i] - '0' + carry) % 10 + '0';
        carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
    }
    if (carry > 0) c = "1" + c;
    return c;
}

string exchangePalindromic(string s) {
    string c;
    for (int i = s.length() - 1; i >= 0; --i) {
        c += s[i];
    }
    return c;
}

long long string2number(string s) {
    long long number = 0;
    for (int i = 0; i < s.length(); ++i) {
        number = number * 10 + (s[i] - '0');
    }
    return number;
}

string number2string(long long number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

int main() {
    string s;
    cin >> s;
    if (isPalindromic(s)) {
        cout << s << " is a palindromic number." << endl;
        return 0;
    }
    for (int i = 0; i < 10; ++i) {
        string bS = exchangePalindromic(s);
        string sum = add(s, bS);
        cout << s << " + " << bS << " = " << sum << endl;
        if (isPalindromic(sum)) {
            cout << sum << " is a palindromic number." << endl;
            return 0;
        }
        s = sum;
    }

    cout << "Not found in 10 iterations." << endl;
}
