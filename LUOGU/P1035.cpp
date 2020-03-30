//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    double sum = 0;
    double index = 1;
    while (sum <= k) {
        sum += (1 / index);
        index++;
    }
    cout << index-1 << endl;
}
