//
// Created by GreenArrow on 2020/2/14.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int candyClassify(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return candyClassify(n-1) + candyClassify(n-2);
}

int main() {
    int n;
    while (cin >> n) {
        cout << candyClassify(n) << endl;
    }
}