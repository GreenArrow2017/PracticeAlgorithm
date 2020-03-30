//
// Created by GreenArrow on 2020/2/11.
//
/**
 * 进制转换
 */

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        long long arr[100010];
        int index = 0;
        do {
            arr[index++] = n % 2;
            n /= 2;
        } while (n > 0);

        for (int i = index - 1; i >= 0; --i) {
            cout << arr[i];
        }
        cout << endl;
    }
}