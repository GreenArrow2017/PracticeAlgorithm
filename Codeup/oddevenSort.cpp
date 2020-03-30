//
// Created by GreenArrow on 2020/2/13.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp_1(int a, int b) {
    return a > b;
}

bool cmp_2(int a, int b) {
    return a < b;
}

int main() {
    int arr[10];
    while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6] >> arr[7] >> arr[8] >> arr[9]) {
        int odd[10], even[10], oddIndex = 0, evenIndex = 0;
        for (int i = 0; i < 10; ++i) {
            if (arr[i] % 2 == 0) {
                even[evenIndex++] = arr[i];
            } else
                odd[oddIndex++] = arr[i];
        }

        sort(odd, odd + oddIndex, cmp_1);
        sort(even, even + evenIndex, cmp_2);

        for (int j = 0; j < oddIndex; ++j) {
            cout << odd[j] << " ";
        }
        for (int k = 0; k < evenIndex; ++k) {
            cout << even[k];
            if (k == evenIndex - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }

    }
}