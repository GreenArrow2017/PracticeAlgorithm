//
// Created by GreenArrow on 2020/2/6.
//

#include <iostream>

using namespace std;

void reverse(int *arr, int left, int right) {
    for (int i = left, j = right; i < j; ++i, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    m = m > n ? m - n : m;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    reverse(arr, 0, n - m - 1);
    reverse(arr, n - m, n - 1);
    reverse(arr, 0, n - 1);
    for (int j = 0; j < n; ++j) {
        cout << arr[j];
        if (j != n - 1) {
            cout << " ";
        }
    }
}
