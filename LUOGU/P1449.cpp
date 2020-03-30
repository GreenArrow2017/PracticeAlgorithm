//
// Created by GreenArrow on 2020/3/5.
//
#include <iostream>
#include <stack>

using namespace std;

int calculate(int a, int b, char c) {
    if (c == '*') {
        return a * b;
    } else if (c == '/') {
        return a / b;
    } else if (c == '-') {
        return a - b;
    } else if (c == '+') {
        return a + b;
    }
}

int main() {
    stack<int> Stack;
    string s;
    cin >> s;
    int num = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '.') {
            Stack.push(num);
            num = 0;
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int b = Stack.top();
            Stack.pop();
            int a = Stack.top();
            Stack.pop();
            int result = calculate(a, b, s[i]);
            Stack.push(result);
        }
    }
    cout << Stack.top() << endl;
}
