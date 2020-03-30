//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> Stack;
    long long a, b;
    cin >> a >> b;
    long long sum = a + b;
    if (sum < 0) {
        sum *= (-1);
        cout << "-";
    }
    int count = 0;
    while (sum >= 10) {
        int index = sum % 10;
        index += '0';
        Stack.push(index);
        count++;
        if (count == 3) {
            count = 0;
            Stack.push(',');
        }
        sum /= 10;
    }
    Stack.push(sum + '0');

    while (!Stack.empty()) {
        cout << Stack.top();
        Stack.pop();
    }
}
