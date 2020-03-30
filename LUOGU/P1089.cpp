//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

using namespace std;

int main() {
    int months[12];
    int sum = 0;
    int month = 0;
    int index = 0;
    for (int i = 0; i < 12; ++i) {
        sum += 300;
        int consume = 0;
        cin >> consume;
        sum -= consume;
        if (sum < 0) {
            index = i + 1;
            break;
        }
        if (sum >= 100) {
            int send = sum / 100;
            month += (send * 100);
            sum -= send * 100;
        }
    }
    if (sum < 0) {
        cout << "-" << index << endl;
        return 0;
    }
    sum += (month * 1.2);
    cout << sum << endl;
}