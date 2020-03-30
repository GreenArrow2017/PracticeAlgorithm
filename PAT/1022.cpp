//
// Created by GreenArrow on 2020/2/11.
//

#include <iostream>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int sum = a + b;
    int arr[31], index = 0;
    do {
        arr[index++] = sum % n;
        sum /= n;
    } while (sum != 0);

    for (int i = index - 1; i >= 0; --i) {
        cout << arr[i];
    }

}