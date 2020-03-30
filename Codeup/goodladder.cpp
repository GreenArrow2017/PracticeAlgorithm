//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {


            int num;
            cin >> num;
            int blank = num - 1;
            int tri = num;
            for (int l = 0; l < num; l++) {
                for (int j = 0; j < blank; ++j) {
                    cout << " ";
                }
                for (int k = 0; k < tri; ++k) {
                    cout << "*";
                }
                cout << endl;
                blank--;
                tri += 2;
            }

        }
    }
}

