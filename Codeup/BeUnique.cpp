//
// Created by GreenArrow on 2020/2/13.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    int array_constaint[100010] = {0};
    while (cin >> n) {
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            array_constaint[arr[i]]++;
        }
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            if (array_constaint[arr[j]] == 1) {
                cout << arr[j] << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "None" << endl;
        }
    }
}