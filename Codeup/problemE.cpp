//
// Created by GreenArrow on 2020/2/17.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            stack<char> stack;
            for (int j = 0; j < s.length(); ++j) {
                if (s[j] == '(' || s[j] == '[' || s[j] == '{') {
                    stack.push(s[j]);
                } else if (s[j] == ']' || s[j] == '}' || s[j] == ')') {
                    if (s[j] == ']' && !stack.empty() && stack.top() == '[') {
                        stack.pop();
                    } else if (s[j] == '}' && !stack.empty() && stack.top() == '{') {
                        stack.pop();
                    } else if (s[j] == ')' && !stack.empty() && stack.top() == '(') {
                        stack.pop();
                    } else{
                        stack.push(s[j]);
                    }
                } else {
                    continue;
                }
            }
            if (stack.empty()) {
                cout << "yes" << endl;
            } else
                cout << "no" << endl;
        }

    }
}