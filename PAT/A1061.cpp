//
// Created by GreenArrow on 2020/3/9.
//
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

string getWeekAndHour(string result) {
    char week = result[0];
    string s;
    if (week == 'A') {
        s += "MON";
    } else if (week == 'B') {
        s += "TUE";
    } else if (week == 'C') {
        s += "WED";
    } else if (week == 'D') {
        s += "THU";
    } else if (week == 'E') {
        s += "FRI";
    } else if (week == 'F') {
        s += "SAT";
    } else if (week == 'G') {
        s += "SUN";
    }

    s += " ";

    char hour = result[1];
    if (hour >= '0' && hour <= '9') {
        s += '0';
        s += hour;
    } else if (hour >= 'A' && hour <= 'N') {
        int h = hour - 'A' + 10;
        stringstream ss;
        ss << h;
        s += ss.str();
    }
    return s;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string result;
    int length = ((s1.length() > s2.length()) ? s2.length() : s1.length());
    bool flag = false;
    for (int i = 0; i < length; ++i) {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G' && !flag) {
            result += s1[i];
            flag = true;
            continue;
        }
        if (s1[i] == s2[i] && s1[i] >= '0' && s1[i] <= '9' && flag) {
            result += s1[i];
        } else if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'N' && flag) {
            result += s1[i];
        }

        if (result.length() == 2) {
            break;
        }
    }

    string s3, s4;
    int index;
    cin >> s3 >> s4;
    int l = ((s3.length() > s4.length()) ? s4.length() : s3.length());
    for (int j = 0; j < l; ++j) {
        if (s3[j] == s4[j] && ((s3[j] >= 'a' && s3[j] <= 'z')||(s3[j] >= 'A' && s3[j] <= 'Z'))) {
            index = j;
            break;
        }
    }

    result = getWeekAndHour(result);

    cout << result << ":";
    printf("%02d\n", index);

}
/**
3485djDkxh4hhGN
2984akDfkkkkggNdsb
s&hgsfdk
d&Hyscvnm


 **/