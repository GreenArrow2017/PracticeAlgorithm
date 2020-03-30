//
// Created by GreenArrow on 2020/3/5.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> Stack;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            Stack.push(s[i]);
        } else if (s[i] == ')') {
            if (!Stack.empty() && Stack.top() == '(') {
                Stack.pop();
                continue;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (s[i] == ']') {
            if (!Stack.empty() && Stack.top() == '[') {
                Stack.pop();
                continue;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (s[i] == '}') {
            if (!Stack.empty() && Stack.top() == '}') {
                Stack.pop();
                continue;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if (!Stack.empty()) {
        cout << "NO" << endl;
        return 0;
    } else
        cout << "YES" << endl;
}
