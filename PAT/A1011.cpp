//
// Created by GreenArrow on 2020/4/1.
//
#include <iostream>

#define MAX 3
using namespace std;

int main() {
    double arr[MAX][MAX];
    int index_[MAX] = {-1};
    for (int i = 0; i < MAX; ++i) {
        double max = -1;
        for (int j = 0; j < MAX; ++j) {
            cin >> arr[i][j];
            if (max < arr[i][j]) {
                index_[i] = j;
                max = arr[i][j];
            }
        }
    }

    string a, b, c;
    double sum = 1;

    for (int k = 0; k < MAX; ++k) {
        if (index_[k] == 0) {
            cout << "W";
        } else if (index_[k] == 1) {
            cout << "T";
        } else if (index_[k] == 2) {
            cout << "L";
        }
        cout << " ";

        sum *= arr[k][index_[k]];

    }

    sum = (sum * 0.65 - 1) * 2;

    printf("%.2lf", sum);


}
