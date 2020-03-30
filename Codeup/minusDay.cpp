//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int month[13][2] = {
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

    int year_front, year_back;
    while (cin >> year_front >> year_back) {
        if (year_front > year_back) {
            int temp = year_front;
            year_front = year_back;
            year_back = temp;
        }

        int year1, month1, day1;
        int year2, month2, day2;
        year1 = year_front / 10000;
        month1 = year_front % 10000 / 100;
        day1 = year_front % 100;

        year2 = year_back / 10000;
        month2 = year_back % 10000 / 100;
        day2 = year_back % 100;


        int an = 1;
        while (year1 < year2 || month1 < month2 || day1 < day2) {
            day1++;
            if (month[month1][isLeap(year1)] + 1 == day1) {
                month1++;
                day1 = 1;
            }
            if (month1 == 13) {
                year1++;
                month1 = 1;
            }
            an++;
        }
        cout << an << endl;
    }

}
