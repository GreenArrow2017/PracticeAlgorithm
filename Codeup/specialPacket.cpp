//
// Created by GreenArrow on 2020/2/14.
//

#include <iostream>

using namespace std;

int arr[10010];

int number(int a, int b) {
    if (b == 0)
        return 1;
    if (a <= 0)
        return 0;
    return number(a - 1, b) + number(a - 1, b - arr[a]);
}

int main() {
    int n;
    while (cin >> n) {

        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        cout << number(n, 40) << endl;
    }
}