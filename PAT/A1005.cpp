//
// Created by GreenArrow on 2020/3/8.
//
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

string add(string result, char a) {
    int carry = 0;
    for (int i = result.length() - 1; i >= 0; --i) {
        int sum = 0;
        if (i == result.length() - 1) {
            sum = ((result[i] - '0') + (a - '0'));
            carry = sum / 10;
            result[i] = (sum % 10) + '0';
        } else {
            sum = (result[i] - '0') + carry;
            carry = sum / 10;
            result[i] = (sum % 10) + '0';
        }
    }
    if (carry > 0) {
        stringstream ss;
        ss << carry;
        return ss.str() + result;
    }
    return result;
}

string change(char a) {
    if (a == '1') {
        return "one";
    } else if (a == '2') {
        return "two";
    } else if (a == '3') {
        return "three";
    } else if (a == '4') {
        return "four";
    } else if (a == '5') {
        return "five";
    } else if (a == '6') {
        return "six";
    } else if (a == '7') {
        return "seven";
    } else if (a == '8') {
        return "eight";
    } else if (a == '9') {
        return "nine";
    } else if (a == '0') {
        return "zero";
    }
}

string getAlpha(string number) {

    string print;
    for (int i = 0; i < number.length(); ++i) {
        print += change(number[i]);
        if (i != number.length() - 1) {
            print += " ";
        }
    }
    return print;

}

int main() {
    string s;
    cin >> s;
    string result = "0";
    for (int i = 0; i < s.length(); ++i) {
        result = add(result, s[i]);
    }
    cout << getAlpha(result);
}

