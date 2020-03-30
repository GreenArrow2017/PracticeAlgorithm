//
// Created by GreenArrow on 2020/2/15.
//

#include <iostream>

using namespace std;
int needs[10020] = {0};
int number = 0;
int arr[1001][1001] = {0};

bool check(int row, int cow, int n) {
    for (int i = row - 1; i >= 0; --i) {
        if (arr[i][cow] == 1) {
            return false;
        }
    }
    for (int i = row - 1, m = cow - 1; i >= 0 && m >= 0; i--, m--) {//检查左对角线
        if (arr[i][m] == 1) {
            return false;
        }
    }
    for (int i = row - 1, m = cow + 1; i >= 0 && m <= n - 1; i--, m++) {//检查右对角线
        if (arr[i][m] == 1) {
            return false;
        }
    }

    return true;
}

void getQueen(int row, int n) {
    if (row >= n) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] == 1) {
                    sum = sum * 10 + (j + 1);
                }
            }
        }
        //cout << sum << endl;
        needs[number++] = sum;
        sum = 0;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (check(row, i, n)) {
            arr[row][i] = 1;
            getQueen(row + 1, n);
            arr[row][i] = 0;
        }
    }
}


int main() {
    int n = 8;
    int m;
    while (cin >> m) {
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = 0;
            }

            getQueen(0, n);

        }
//
//        for (int l = 0; l < number; ++l) {
//            cout << needs[l] << " ";
//        }

        //sort(needs, needs + number);



        int num = 0;
        for (int k = 0; k < m; ++k) {
            cin >> num;
            cin.ignore();
            cout << needs[num - 1] << endl;
        }

    }
}