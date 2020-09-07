//
// Created by GreenArrow on 2020/4/6.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> getNumber(int number, int radix) {
    vector<int> sequences;
    while (number >= radix) {
        sequences.push_back(number % radix);
        number /= radix;
    }
    sequences.push_back(number);
    return sequences;
}

bool isPalindromic(vector<int> sequences) {
    for (int i = 0, j = sequences.size() - 1; i < j; ++i, j--) {
        if (sequences[i] != sequences[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int number, radix;
    cin >> number >> radix;
    vector<int> sequences = getNumber(number, radix);
    if (isPalindromic(sequences)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    for (int i = sequences.size() - 1; i >= 0; --i) {
        cout << sequences[i];
        if (i != 0) {
            cout << " ";
        }
    }
}