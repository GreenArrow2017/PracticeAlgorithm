//
// Created by GreenArrow on 2020/2/6.
//
#include <iostream>

using namespace std;

class Stack {
private:
    string *arr;
    int top = -1;
    int number = 0;
    int size = 10000;
public:
    void allocateMemory() {
        arr = (string *) malloc(size * sizeof(string));
    }

    void push(string s) {
        arr[++top] = s;
    }

    string pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack stack;
    stack.allocateMemory();
    string s;
    getline(cin, s);
    string word = "";
    for (char c : s) {
        if (c != ' ') {
            word += c;
        } else {
            stack.push(word);
            word = "";
        }
    }

    stack.push(word);

    while (!stack.isEmpty()){
        cout<<stack.pop();
        if (!stack.isEmpty()){
            cout << " ";
        }
    }

        return 0;
}

