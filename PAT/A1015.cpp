//
// Created by GreenArrow on 2020/4/2.
//
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int number) {
    if (number == 2) {
        return true;
    }

    if (number == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> getReverse(int number, int radix) {
    vector<int> results;
    while (number >= radix) {
        results.push_back(number % radix);
        number /= radix;
    }

    results.push_back(number);
    return results;
}

int radix2number(vector<int> result, int radix) {

    int sum = 0;
    for (int i = 0; i < result.size(); ++i) {
        sum = sum * radix + result[i];
    }

    return sum;

}

int main() {
    int number, radix;
    cin >> number;
    while (number > 0) {
        cin >> radix;

        if (isPrime(number)) {

            int reversNumber = radix2number(getReverse(number, radix), radix);
            if (isPrime(reversNumber)) {
                cout << "Yes" << endl;
            } else
                cout << "No" << endl;

        } else {
            cout << "No" << endl;
        }
        cin >> number;
    }
    return 0;
}