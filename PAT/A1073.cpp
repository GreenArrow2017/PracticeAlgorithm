//
// Created by GreenArrow on 2020/3/9.
//

#include <iostream>

using namespace std;

int getNotion(string notation) {
    int sum = 0;
    for (int i = 1; i < notation.length(); ++i) {
        sum = sum * 10 + (notation[i] - '0');
    }
    return sum;
}

int main() {
    string s;
    cin >> s;
    int index = 0;
    int sign = 1;
    if (s[index] == '-') {
        sign = -1;
        index++;
    } else if (s[index] == '+') {
        sign = 1;
        index++;
    }

    string notation;
    bool flag = false;
    int point = 0;
    int point_position;
    for (int i = index; i < s.length(); ++i) {
        if (s[i] == 'E') {
            flag = true;
            point = i;
            continue;
        }
        if (flag) {
            notation += s[i];
        }
    }


    string real = s.substr(index, point - index);

    for (int j = 0; j < real.length(); ++j) {
        if (real[j] == '.') {
            point_position = j;
        }

    }

    int left_point = point_position;
    int right_point = real.length() - point_position - 1;


    if (notation[0] == '+') {
        int num = getNotion(notation);
        if (num == right_point) {
            if (sign == -1) {
                cout << "-";
            }
            for (int i = 0; i < real.length(); ++i) {
                if (real[i] != '.') {
                    cout << real[i];
                }
            }
            return 0;
        } else if (num < right_point) {
            int cur;
            int i = 0;
            for (cur = point_position, i = 0; i < num; ++i, cur++) {
                real[cur] = real[cur + 1];
            }
            real[cur] = '.';
            if (sign == -1) {
                cout << "-";
            }
            cout << real;
            return 0;
        } else if (num > right_point) {
            int number = num - right_point;
            if (sign == -1) {
                cout << "-";
            }
            for (int i = 0; i < real.length(); ++i) {
                if (real[i] != '.') {
                    cout << real[i];
                }
            }
            for (int j = 0; j < number; ++j) {
                cout << "0";
            }
            return 0;
        }
    } else if (notation[0] == '-') {
        int num = getNotion(notation);
        if (num == left_point) {
            if (sign == -1) {
                cout << "-";
            }
            cout << "0.";
            for (int i = 0; i < real.length(); ++i) {
                if (real[i] != '.')
                    cout << real[i];
            }
            return 0;
        } else if (num > left_point) {
            int numberLeft = num - left_point;
            if (sign == -1) {
                cout << "-";
            }
            cout << "0.";
            for (int i = 0; i < numberLeft; ++i) {
                cout << "0";
            }
            for (int i = 0; i < real.length(); ++i) {
                if (real[i] != '.')
                    cout << real[i];
            }
        } else if (num < left_point) {
            int cur, k;
            for (k = 0, cur = point_position; k < num; ++k, --cur) {
                real[cur - 1] = real[cur];
            }
            real[cur] = ',';
            if (sign == -1) {
                cout << "-";
            }
            cout << real;
            return 0;
        }
    }
}