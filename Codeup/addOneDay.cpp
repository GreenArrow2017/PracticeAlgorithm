//
// Created by GreenArrow on 2020/2/11.
//

#include <iostream>

using namespace std;

int month_groble[13][2] = {
        {0,  0},
        {31, 31},
        {28, 29},
        {31, 31},
        {30, 30},
        {31, 31},
        {30, 30},
        {31, 31},
        {31, 31},
        {30, 30},
        {31, 31},
        {30, 30},
        {31, 31}
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {


            int year;
            int month;
            int day;
            cin >> year >> month >> day;
            day++;
            if (day == month_groble[month][isLeap(year)] + 1) {
                day = 1;
                month++;
            }

            if (month == 13) {
                month = 1;
                year++;
            }

            cout << year << "-";
            if (month < 10) {
                cout << "0";
            }
            cout << month << "-";
            if (day < 10) {
                cout << "0";
            }
            cout << day << endl;


        }
    }
}

