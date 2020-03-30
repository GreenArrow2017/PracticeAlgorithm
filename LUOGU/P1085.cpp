//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

using namespace std;

int main() {
    int happy[7];
    int max = -1;
    int index = -1;
    for (int i = 0; i < 7; ++i) {
        int a, b;
        cin >> a >> b;
        happy[i] = a + b;
        if (max < happy[i]) {
            max = happy[i];
            index = i + 1;
        }
    }
    if (max > 8) {
        cout << index << endl;
    } else {
        cout << 0 << endl;
    }
}