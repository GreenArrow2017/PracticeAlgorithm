//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {


        int blank = 0;
        int number = n + n - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < blank; ++j) {
                cout << " ";
            }
            for (int k = 0; k < number; ++k) {
                if (k % 2 == 0) {
                    cout << "*";
                } else
                    cout << " ";
            }
            blank++;
            number -= 2;
            cout << endl;
        }

        blank -= 2;
        number += 4;

        for (int i = 0; i < n - 1; ++i) {

            for (int j = 0; j < blank; ++j) {
                cout << " ";
            }
            for (int k = 0; k < number; ++k) {
                if (k % 2 == 0) {
                    cout << "*";
                } else
                    cout << " ";
            }
            cout << endl;
            blank--;
            number += 2;
        }


    }
}

/**
        if (!exchange) {
            n = ((week + 7 - bias) % 7);
        } else
            n = (week + bias) % 7;
            **/