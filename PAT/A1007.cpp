//
// Created by GreenArrow on 2020/3/30.
//
#include <iostream>
#include <climits>

using namespace std;

int maxSum = INT_MIN;
int start = -1;
int end = -1;

int getMax(int *array, int l, int r, int &left, int &right) {
    if (l == r) {
        left = right = array[l];
        return array[l];
    }
    int mid = (l + r) / 2;
    int maxLeft = INT_MIN;
    int maxLeftIndex = -1;
    int tempLeft = 0;
    for (int i = mid; i >= l; --i) {
        tempLeft += array[i];
        if (tempLeft > maxLeft) {
            maxLeftIndex = i;
            maxLeft = tempLeft;
        }
    }


    int maxRight = INT_MIN;
    int maxRightIndex = -1;
    int tempRight = 0;
    for (int i = mid + 1; i <= r; ++i) {
        tempRight += array[i];
        if (tempRight > maxRight) {
            maxRightIndex = i;
            maxRight = tempRight;
        }
    }


    int Lleft, Lright;
    int Rleft, Rright;

    int midSum = maxLeft + maxRight;
    int maxLeftSum = getMax(array, l, mid, Lleft, Lright);
    int maxRightSum = getMax(array, mid + 1, r, Rleft, Rright);


    int max = midSum;
    left = array[maxLeftIndex], right = array[maxRightIndex];


    if (max <= maxLeftSum) {
        max = maxLeftSum;
        left = array[Lleft];
        right = array[Lright];
    }
    if (max < maxRightSum) {
        max = maxRightSum;
        left = array[Rleft];
        right = array[Rright];
    }


    return max;

}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0 0 0";
        return 0;
    }
    int array[10000];
    bool negative = true;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        if (array[i] >= 0) {
            negative = false;
        }
    }

    if (negative) {
        cout << "0 " << array[0] << " " << array[n - 1];
        return 0;
    }

    int left, right;

    cout << getMax(array, 0, n - 1, left, right) << " " << left << " " << right;
    return 0;
}
