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
        if (n == 1) {
            cout << arr[0] << endl;
            cout << "-1" << endl;
        } else {
            cout << arr[n - 1] << endl;
            for (int j = 0; j < n - 1; ++j) {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
    }

}