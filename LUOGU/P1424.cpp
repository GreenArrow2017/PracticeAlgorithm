//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

using namespace std;

int main() {
    int day;
    int time;
    int sum = 0;
    cin >> day >> time;
    while (time--) {
        if (!(day == 6 || day == 7)) {
            sum += 250;
        }

        day++;
        if (day == 8) {
            day = 1;
        }
    }
    cout << sum << endl;
}
