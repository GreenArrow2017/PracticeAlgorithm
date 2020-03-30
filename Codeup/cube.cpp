//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int main() {
    char c;
    int n;
    cin >> n >> c;
    if (n == 1) {
        cout << c;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << c;
    }
    cout << endl;
    int sep = (n % 2 == 0 ? n / 2 : n / 2 + 1);
    for (int j = 0; j < (sep - 2); ++j) {
        cout << c;
        for (int i = 0; i < n - 2; ++i) {
            cout << " ";
        }
        cout << c << endl;
    }
    for (int i = 0; i < n; ++i) {
        cout << c;
    }
}
