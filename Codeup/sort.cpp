//
// Created by GreenArrow on 2020/2/12.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for (int j = 0; j < n; ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}