//
// Created by GreenArrow on 2020/2/18.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {

        cin.ignore();
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cin.ignore();
        int m;
        cin >> m;
        cin.ignore();
        int brr[m];

        for (int j = 0; j < m; ++j) {
            cin >> brr[j];
        }

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        for (int j = 0; j < m; ++j) {
            cout << brr[j];
            if (j != m - 1) {}
            cout << " ";
        }

        cin.ignore();
        cout << endl;


    }
}