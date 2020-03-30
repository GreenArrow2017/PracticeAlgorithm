//
// Created by GreenArrow on 2020/2/11.
//

#include <iostream>

using namespace std;

string getWeek(int n) {
    if (n == 1)
        return "Monday";
    else if (n == 2)
        return "Tuesday";
    else if (n == 3)
        return "Wednesday";
    else if (n == 4)
        return "Thursday";
    else if (n == 5)
        return "Friday";
    else if (n == 6)
        return "Saturday";
    else if (n == 0)
        return "Sunday";
    else
        return "n == " + n;
}

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getMonth(string Month) {
    if (Month == "January") {
        return 1;
    } else if (Month == "February") {
        return 2;
    } else if (Month == "March") {
        return 3;
    } else if (Month == "April") {
        return 4;
    } else if (Month == "May") {
        return 5;
    } else if (Month == "June") {
        return 6;
    } else if (Month == "July") {
        return 7;
    } else if (Month == "August") {
        return 8;
    } else if (Month == "September") {
        return 9;
    } else if (Month == "October") {
        return 10;
    } else if (Month == "November") {
        return 11;
    } else if (Month == "December") {
        return 12;
    }
}

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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {


    int Day;
    string Month;
    int Year;
    while (cin >> Day >> Month >> Year) {
        int year = 2020;
        int month = 2;
        int day = 11;
        int week = 2;

        int Mon = getMonth(Month);
        int sum = 0;
        bool exchange = false;

        if (Year > year) {
            swap(Year, year);
            swap(Mon, month);
            swap(day, Day);
            exchange = true;
        }

        if (Year == year && Mon > month) {
            swap(Year, year);
            swap(Mon, month);
            swap(day, Day);
            exchange = true;

        }

        //day > Day
        if (Year == year && Mon == month && Day > day) {
            swap(Year, year);
            swap(Mon, month);
            swap(day, Day);
            exchange = true;
        }

        while (Year < year || Mon < month || Day < day) {
            Day++;
            if (Day == month_groble[Mon][isLeap(Year)] + 1) {
                Mon++;
                Day = 1;
            }
            if (Mon == 13) {
                Year++;
                Mon = 1;
            }
            sum++;
        }


        int bias = sum % 7;
        //cout << bias << endl;
        int n;
        if (!exchange)
            n = ((week + 7 - bias) % 7);
        else
            n = (week + bias) % 7;
        //cout << n << endl;
        cout << getWeek(n) << endl;
    }
}