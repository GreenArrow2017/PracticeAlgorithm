//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

#define single 19
using namespace std;

int main() {
    long long money1, money2;
    cin >> money1 >> money2;
    long long sum = money1 * 10 + money2;
    cout << sum / single << endl;

}