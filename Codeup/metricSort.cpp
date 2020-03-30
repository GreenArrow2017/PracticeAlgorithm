//
// Created by GreenArrow on 2020/2/13.
//

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    while (cin >> n) {
        int a[10010];
        int arr[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }

        int index = 0;
        int line1 = 0;
        int line2 = 0;
        for (int k = 0; k < n; ++k) {
            int sum = 0;
            int sum2 = 0;

            for (int i = 0; i < n; ++i) {
                sum += arr[k][i];
                sum2 += arr[i][k];
                if (k == i) {
                    line1 += arr[k][i];
                }
                if (k + i == n - 1) {
                    line2 += arr[k][i];
                }
            }
            a[index++] = sum;
            a[index++] = sum2;
        }
        a[index++] = line1;
        a[index++] = line2;
        sort(a, a + index, cmp);
        for (int l = 0; l < index; ++l) {
            cout << a[l];
            if (l == index - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
}