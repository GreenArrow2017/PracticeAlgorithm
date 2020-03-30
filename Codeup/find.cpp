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
        int find[num];
        for (int j = 0; j < num; ++j) {
            cin >> find[j];
        }
        for (int k = 0; k < num; ++k) {
            bool flag = false;
            for (int i = 0; i < n; ++i) {
                if (find[k] == arr[i]) {
                    flag = true;
                }
            }
            if (flag) {
                cout << "YES" << endl;
            } else
                cout << "NO" << endl;
        }
    }
}