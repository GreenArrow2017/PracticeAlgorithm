//
// Created by GreenArrow on 2020/2/6.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    int pre = 2;
    int count = 0, j = 0;
    for (int i = 3; i <= n; ++i) {
        for (j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                break;
            }
        }
        if (j > sqrt(i)) {
            if (i - pre == 2) {
                count++;
            }
            pre = i;
        }
    }
    cout << count;
    return 0;
}