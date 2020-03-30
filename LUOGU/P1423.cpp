//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

using namespace std;

int main() {
    int count = 1;
    double result;
    cin >> result;
    double sum = 2;
    double step = 2;
    while (sum <= result) {
        sum += step * 0.98;
        step *= 0.98;
        count++;
    }
    cout << count << endl;
}
