//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    double n;
    cin >> n;
    double result = 0;
    if (n <= 150) {
        result = n * 0.4463;
    } else if (n > 150 && n <= 400) {
        result += (150 * 0.4463 + (n - 150) * 0.4663);
    } else if (n > 400) {
        result += (150 * 0.4463 + (400 - 150) * 0.4663 + (n - 400) * 0.5663);
    }
    printf("%.1lf", result);
    return 0;
}
