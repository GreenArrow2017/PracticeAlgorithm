//
// Created by GreenArrow on 2020/3/10.
//
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

long long string2long(const string &s) {
    long long sum = 0;
    for (char i : s) {
        sum = sum * 10 + (i - '0');
    }
    return sum;
}

bool isPrime(const string &number_) {
    long long number = string2long(number_);
    if (number == 2) {
        return true;
    } else if (number == 1) {
        return false;
    }
    bool flag = true;
    for (int i = 2; i < sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return flag;
}

int main() {
    int n;
    int num;
    cin >> n >> num;
    string s;
    cin >> s;
    map<string, bool> isPrime_map;

    for (int i = 0; i < n - num + 1; ++i) {
        string next = s.substr(i, num);
        if (isPrime_map.find(next) == isPrime_map.end()) {
            bool flag = isPrime(next);
            if (flag) {
                cout << next;
                return 0;
            } else {
                isPrime_map[next] = flag;
            }
        } else {
            if (isPrime_map[next]) {
                cout << next;
                return 0;
            }
        }
    }
    cout << 404;
}
