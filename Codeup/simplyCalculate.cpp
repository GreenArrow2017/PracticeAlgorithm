//
// Created by GreenArrow on 2020/2/17.
//

#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>

using namespace std;

class Stack {
private:
    char arr[2000];
    int top = -1;
    int number = 0;

public:
    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    char get() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

class Queue {
private:
    double arr[2000];
    int front = 0;
    int rear = 0;
    int contain = 2000;

public:
    void push(double num) {
        if ((rear + 1) % contain == front) {
            cout << "队列已满" << endl;
            return;
        }
        arr[rear] = num;
        rear = (rear + 1) % contain;
    }

    double pop() {
        if (rear == front) {
            cout << "队列为空" << endl;
        }
        double num = arr[front];
        front = (front + 1) % contain;
        return num;
    }

    double view() {
        if (rear == front) {
            cout << "队列为空" << endl;
        }
        return arr[(front + 1) % contain];
    }
};

int string2number(string s) {
    int num = 0;
    for (char c : s) {
        num = num * 10 + (c - '0');
    }
    return num;
}

double calculate(double a, double b, char c) {
    if (c == '+') {
        return a + b;
    }

    if (c == '-') {
        return a - b;
    }

    if (c == '*') {
        return a * b;
    }

    if (c == '/') {
        return a / b;
    }
}

int main() {

    string s;
    while (getline(cin, s)) {
        if(s == "0"){
            return 0;
        }
        stack<char> sta;
        stack<double> queue;
        for (int i = 0; i < s.length(); ++i) {
            char test = s[i];
            if (s[i] == ' ') {
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                int index = i + 1;
                string number = "";
                number += s[i];
                while (s[index] >= '0' && s[index] <= '9') {
                    number += s[index++];
                }
                i = index;

                queue.push(string2number(number));
            } else if (s[i] == '+' || s[i] == '-') {
                if (sta.empty()) {
                    sta.push(s[i]);
                } else {
                    while (!sta.empty()) {
                        double a = queue.top();
                        queue.pop();
                        double b = queue.top();
                        queue.pop();
                        char c = sta.top();
                        sta.pop();
                        double result = calculate(b, a, c);
                        queue.push(result);
                    }
                    sta.push(s[i]);
                }
            } else if (s[i] == '*' || s[i] == '/') {
                if (sta.empty() || sta.top() == '+' || sta.top() == '-') {
                    sta.push(s[i]);
                } else {
                    while (!sta.empty() && (sta.top() == '*' || sta.top() == '/')) {
                        double a = queue.top();
                        queue.pop();
                        double b = queue.top();
                        queue.pop();
                        char c = sta.top();
                        sta.pop();
                        double result = calculate(b, a, c);
                        queue.push(result);
                    }
                    sta.push(s[i]);
                }

            }
        }

        while (!sta.empty()) {
            double a = queue.top();
            queue.pop();
            double b = queue.top();
            queue.pop();
            char c = sta.top();
            sta.pop();
            double result = calculate(b, a, c);
            queue.push(result);
        }

        printf("%.2lf\n", queue.top());
    }

}