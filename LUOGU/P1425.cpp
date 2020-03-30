//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>

using namespace std;

int main() {

    int beginHour, beginMinute;
    int endHour, endMinute;
    int time = 0;
    cin >> beginHour >> beginMinute >> endHour >> endMinute;
    while (beginHour < endHour || beginMinute < endMinute) {
        beginMinute++;
        time++;
        if (beginMinute == 61) {
            beginMinute = 1;
            beginHour++;
        }
    }
    int hour = time / 60;
    int minute = time % 60;
    cout << hour << " " << minute << endl;

}