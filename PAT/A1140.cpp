//
// Created by GreenArrow on 2020/3/10.
//
#include <iostream>
#include <sstream>

using namespace std;

string number2string(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

int main() {
    string sequence[50];
    char D;
    int n;
    cin >> D >> n;
    sequence[0] = D;
    for (int i = 1; i < n; ++i) {
        string pre = sequence[i - 1];
        string result;
        for (int j = 0; j < pre.length(); ++j) {
            int number = 1, index = j;
            while (index + 1 < pre.length() && pre[index] == pre[index + 1]) {
                number++;
                index++;
            }
            result += (pre[j] + number2string(number));
            j = index;
        }
        sequence[i] = result;
    }
    cout << sequence[n - 1];
}
