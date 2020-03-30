//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int num;
        cin >> num;
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            if (arr[j] == num) {
                cout << j << endl;
                flag = true;
            }
        }
        if (flag == false) {
            cout << -1 << endl;
        }
    }
}

