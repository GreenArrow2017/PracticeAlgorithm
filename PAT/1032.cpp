//
// Created by GreenArrow on 2020/2/8.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[100010] = {0};

    for (int i = 0; i < n; ++i) {
        int num, score;
        scanf("%d %d", &num, &score);
        arr[num] += score;
    }
    int max = -2100000;
    int index = -1;
    for (int k = 0; k <= n; ++k) {
        if (arr[k] > max) {
            max = arr[k];
            index = k;
        }
    }

    cout << index << " " << max;
}