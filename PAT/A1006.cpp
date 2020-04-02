//
// Created by GreenArrow on 2020/3/30.
//
#include <iostream>

using namespace std;

class sepration {
public:
    int hour = -1;
    int min = -1;
    int second = -1;

    sepration() {}

    sepration(int hour, int min, int second) {
        this->hour = hour;
        this->min = min;
        this->second = second;
    }
};

sepration getSepration(string time) {
    int sum = 0;
    sepration s;
    for (int i = 0; i < time.size(); ++i) {
        if (time[i] != ':') {
            sum = sum * 10 + (time[i] - '0');
        } else {
            if (s.hour == -1) {
                s.hour = sum;
            } else if (s.min == -1) {
                s.min = sum;
            }
            sum = 0;
        }
    }
    s.second = sum;
    return s;
}

int main() {
    int n;
    cin >> n;
    int minHour = 60, minMin = 60, minSecond = 60;
    string minName;
    int maxHour = -1, maxMin = -1, maxSecond = -1;
    string maxName;
    for (int i = 0; i < n; ++i) {
        string name, start_time, end_time;
        cin >> name >> start_time >> end_time;
        sepration startTime = getSepration(start_time);
        sepration endTime = getSepration(end_time);

        if(startTime.hour < minHour){
            minHour = startTime.hour;
            minMin = startTime.min;
            minSecond = startTime.second;
            minName = name;
        } else if(startTime.hour == minHour && startTime.min < minMin){
            minHour = startTime.hour;
            minMin = startTime.min;
            minSecond = startTime.second;
            minName = name;
        } else if(startTime.hour == minHour && startTime.min == minMin && startTime.second < minSecond){
            minHour = startTime.hour;
            minMin = startTime.min;
            minSecond = startTime.second;
            minName = name;
        }

        if(endTime.hour > maxHour){
            maxHour = endTime.hour;
            maxMin = endTime.min;
            maxSecond = endTime.second;
            maxName = name;
        } else if(endTime.hour == maxHour && endTime.min < maxMin){
            maxHour = endTime.hour;
            maxMin = endTime.min;
            maxSecond = endTime.second;
            maxName = name;
        } else if(endTime.hour == maxHour && endTime.min == maxMin && endTime.second < maxSecond){
            maxHour = endTime.hour;
            maxMin = endTime.min;
            maxSecond = endTime.second;
            maxName = name;
        }

    }

    cout << minName <<  " " << maxName;
}
