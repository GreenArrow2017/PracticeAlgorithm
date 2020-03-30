//
// Created by GreenArrow on 2020/3/5.
//
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

#define MAX 200200
using namespace std;

int findMax(int l, int r, int *array) {
    if (l == r) {
        return array[l];
    }
    int mid = (l + r) >> 1;
    int left = 0;
    int right = 0;
    int maxMid1 = INT_MIN;
    int maxMid2 = INT_MIN;
    for (int i = mid; i >= l; --i) {
        left += array[i];
        maxMid1 = max(left, maxMid1);
    }
    for (int j = mid + 1; j <= r; ++j) {
        right += array[j];
        maxMid2 = max(right, maxMid2);
    }

    return max(max(findMax(l, mid, array), findMax(mid + 1, r, array)), maxMid1 + maxMid2);
}

int main() {
    int n;
    int array[MAX];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    cout << (findMax(0, n - 1, array));

}

/**
 *
9
-2 1 -3 4 -1 2 1 -5 4
**/