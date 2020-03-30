//
// Created by GreenArrow on 2020/3/9.
//
#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>

using namespace std;

bool getNumber(string s, double &sum) {
    int i;
    int sign = 1;
    int index = 0;
    if (s[0] == '-') {
        index++;
        sign = -1;
    } else if (s[0] == '+') {
        index++;
        sign = 1;
    }
    for (i = index; i < s.length(); ++i) {
        if (s[i] == '.') {
            break;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            sum = sum * 10 + (s[i] - '0');
        } else {
            return false;
        }
    }
    double k = 0.1;
    int index_point = 0;
    for (int j = i + 1; j < s.length(); ++j) {
        if (s[j] >= '0' && s[j] <= '9') {
            sum += (s[j] - '0') * k;
            index_point++;
            if (index_point > 2) {
                return false;
            }
        } else
            return false;
        k *= 0.1;
    }

    sum *= sign;

    return sum >= -1000 && sum <= 1000;

}

int main() {
    int n;
    cin >> n;
    string s;
    vector<double> numbers;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        double sum = 0;
        if (getNumber(s, sum)) {
            numbers.push_back(sum);
            ans += sum;
        } else {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
    }

    if (numbers.size() >= 2)
        cout << "The average of " << numbers.size() << " numbers is ";
    else if (numbers.size() == 1)
        cout << "The average of " << numbers.size() << " number is ";
    if (numbers.size() == 0) {
        cout << "The average of " << numbers.size() << " numbers is ";
        printf("Undefined");
    } else
        printf("%.2lf", ans / numbers.size());

}
