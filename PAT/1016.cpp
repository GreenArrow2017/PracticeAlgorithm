//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

using namespace std;

int main() {
    string A;
    char a;
    string B;
    char b;
    cin >> A >> a >> B >> b;
    int sumA = 0, sumB = 0;
    for (int i = 0; i < A.length(); ++i) {
        if (A[i] == a) {
            sumA = sumA * 10 + (a - '0');
        }
    }

    for (int i = 0; i < B.length(); ++i) {
        if (B[i] == b) {
            sumB = sumB * 10 + (b - '0');
        }
    }

    cout << sumA + sumB << endl;
}
