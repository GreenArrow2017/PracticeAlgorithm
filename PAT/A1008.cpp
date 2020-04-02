//
// Created by GreenArrow on 2020/3/30.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> seperator(string s) {
    int sum = 0;
    vector<int> arr;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ')
            sum = sum * 10 + (s[i] - '0');
        else {
            arr.push_back(sum);
            sum = 0;
        }
    }
    arr.push_back(sum);
    return arr;
}

int main() {
    int n;
    vector<int> array;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        int num;
        cin >> num;
        array.push_back(num);
    }
    int time = 0;
    int pre = 0;
    for (int i = 0; i < array.size(); ++i) {
        int cur = array[i];
        if (cur - pre > 0) {
            time += (cur - pre) * 6;
        } else if (cur - pre < 0) {
            time += (pre - cur) * 4;
        }

        time += 5;
        pre = cur;
    }
    cout << time;
}
