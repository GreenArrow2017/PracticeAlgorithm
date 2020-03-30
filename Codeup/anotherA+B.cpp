//
// Created by GreenArrow on 2020/2/11.
//

#include <iostream>

using namespace std;

int main() {
    long long n, a, b;
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        cin >> a >> b;
        long long sum = a + b;
        long long arr[100], index = 0;
        do {
            arr[index++] = sum % n;
            sum /= n;
        } while (sum != 0);

        for (int i = index - 1; i >= 0; --i) {
            cout << arr[i];
        }
        cout << endl;
    }
}