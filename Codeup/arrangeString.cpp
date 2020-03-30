//
// Created by GreenArrow on 2020/2/12.
//

#include <iostream>

using namespace std;

class stack {
private:
    string arr[100010];
    int top = -1;
    int number = 0;
public:
    void push(string s) {
        arr[++top] = s;
        number++;
    }

    string pop() {
        return arr[top--];
        number--;
    }

    int getSum() {
        return number;
    }

    int isEmpty() {
        return top == -1;
    }

    void showFour() {
        int number = top;
        for (int i = 0; i < 4 && number != -1; ++i) {
            cout << i + 1 << "=" << arr[number--] << " ";
        }
        cout << endl;
    }


};

int main() {
    int n;
    while (cin >> n) {
        stack stack;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            stack.push(s);
            stack.showFour();
        }
    }
}