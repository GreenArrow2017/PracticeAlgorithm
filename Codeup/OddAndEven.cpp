//
// Created by GreenArrow on 2020/2/8.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            int num = 0;
            cin >> num;
            if (num % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if (even > odd) {
            cout << "NO" << endl;
        } else
            cout << "YES" << endl;

    }

}

