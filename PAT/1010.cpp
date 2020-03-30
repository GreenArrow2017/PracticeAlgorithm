//
// Created by GreenArrow on 2020/2/6.
//
/**
 * 真的巨坑，挖槽这他妈两个数之间的空格是可能有多个的，还是用scanf好，直接
 * %d %d就好了，Java的话可以使用正则表达式，\\s+；接着就是什么都没有的时候
 * 注意输出0 0.
 */
#include <iostream>

using namespace std;

int change(string s);

int seperate(string s, string *arr);

void seperate2number(string *a, int *b, int n);

void calculate(int *b, int n);

int seperate(string s, string *arr) {
    string word = "";
    int index = 0;
    for (char c:s) {
        if (c != ' ') {
            word += c;
        } else if (word != "") {
            arr[index++] = word;
            word = "";
        }
    }

    arr[index++] = word;
    return index;
}

void seperate2number(string *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = change(a[i]);
        // cout << b[i] << " ";
    }
    //cout << endl;
}

int change(string s) {
    int index = 0, sign = 1;
    if (s[index] == '-') {
        sign = -1;
        index++;
    } else if (s[index] == '+') {
        sign = 1;
        index++;
    }
    int num = 0;
    for (int i = index; i < s.length(); ++i) {
        num = num * 10 + (s[i] - '0');
    }
    return num * sign;
}

void calculate(int *b, int n) {
    int number = 0, x = 0;
    for (int i = 0; i < n; i += 2) {
        number = b[i];
        x = b[i + 1];
        number = x * number;
        x--;
        if (x == -1) {
            number = 0;
            x = 0;
        }
        b[i] = number;
        b[i + 1] = x;
    }
}

int main() {
    string s;
    int n;
    getline(cin, s);
    string arr[10000];
    int b[10000];
    int c[10000];
    n = seperate(s, arr);

    seperate2number(arr, b, n);

    calculate(b, n);
    int index = 0;
    for (int i = 0; i < n; i += 2) {
        if (b[i] != 0) {
            c[index++] = b[i];
            c[index++] = b[i + 1];
        }
    }
    for (int j = 0; j < index; ++j) {
        cout << c[j];
        if (j != index - 1) {
            cout << " ";
        }
    }
    if (index == 0) {
        cout << 0 << " " << 0;
    }
}