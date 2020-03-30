//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

#define MAX 1000010
using namespace std;
int d[10] = {0};

int main() {
    int num, k;
    cin >> num >> k;
    for (int i = 1; i <= num; ++i) {

        int result = i;
        while (result >= 10) {
            int index = result % 10;
            d[index]++;
            result /= 10;
        }
        d[result]++;

    }

    cout << d[k] << endl;
}
