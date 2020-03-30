//
// Created by GreenArrow on 2020/2/14.
//
#include <iostream>

using namespace std;

void setArray(int n, int *arr) {
    int num = 2 * n - 1;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i <= num; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            int arr[10010];
            setArray(m, arr);
            int blank = 2*(m - 1);
            int element = 1;
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < blank; ++k) {
                    cout << " ";
                }
                for (int l = 0; l < element; ++l) {
                    cout << arr[l];
                    if (l != element - 1) {
                        cout << " ";
                    }
                }
                blank-=2;
                element += 2;
                cout << endl;
            }
        }
    }
}
