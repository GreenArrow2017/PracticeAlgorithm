//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>
#include <algorithm>
using namespace std;

long n, a1, a2, b1, b2, c1, c2, pen1, pen2, pen3, x[3];

int compare(int a1, int a2, int b1, int b2, int c1, int c2) {
    while (pen1 < n) {
        pen1 += a1;
        x[0] += a2;
    }
    while (pen2 < n) {
        pen2 += b1;
        x[1] += b2;
    }
    while (pen3 < n) {
        pen3 += c1;
        x[2] += c2;
    }
    return 0;
}

int main() {
    cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    compare(a1, a2, b1, b2, c1, c2);
    sort(x, x + 3);
    cout << x[0];
    return 0;
}
