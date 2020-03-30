//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int blank = (n - 1) * 2;
        int width = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < blank; ++j) {
                cout << " ";
            }
            for (int k = 0; k < width; ++k) {
                cout << "*";
            }
            cout << endl;
            blank -= 2;
            width += 2;
        }
    }
}
