//
// Created by GreenArrow on 2020/3/2.
//
//#include <iostream>
//
//#define MAX 13
//using namespace std;
//int chess[MAX][MAX] = {0};
//int number = 0;
//int index_ = 0;
//int pre[MAX];
//
//void cancel(int column, int row, int n);
//
//bool check(int column, int row, int n);
//
//void occupy(int column, int row, int n);
//
//void print_chess(int n) {
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (chess[i][j]) {
//                cout << j + 1 << " ";
//            }
//        }
//    }
//    cout << endl;
//}
//
//void print_chess_test(int n) {
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << chess[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//void findQueue(int index, int n) {
//
//    if (index == n) {
//        number++;
//        index_++;
//        if (index_ > 3)
//            return;
//        //print_chess(n);
//        for (int i = 0; i < n; ++i) {
//            cout << pre[i] + 1 << " ";
//        }
//        cout << endl;
//        return;
//    }
//
//    for (int i = 0; i < n; ++i) {
//        if (check(index, i, n)) {
//            chess[index][i] = true;
//            pre[index] = i;
//            findQueue(index + 1, n);
//            chess[index][i] = false;
//        }
//
//    }
//
//}
//
//void findQueue2(int index, int n) {
//
//    if (index == n) {
//        number++;
//        index_++;
//        if (index_ > 3)
//            return;
//        //print_chess(n);
//        for (int i = 0; i < n; ++i) {
//            cout << pre[i] + 1 << " ";
//        }
//        cout << endl;
//        return;
//    }
//
//    print_chess_test(n);
//
//    for (int i = 0; i < n; ++i) {
//
//        if (chess[index][i] == 0) {
//            chess[index][i]++;
//            occupy(index, i, n);
//            findQueue2(index + 1, n);
//            chess[index][i]--;
//            cancel(index, i, n);
//        }
//
//    }
//
//}
//
//void occupy(int column, int row, int n) {
//    for (int i = 0; i < n; ++i) {
//        if (i == column)
//            continue;
//        chess[i][row]++;
//    }
//    for (int i = column, j = row; i >= 0 && j >= 0; --i, j--) {
//        if (i == column && j == row)
//            continue;
//        chess[i][j]++;
//    }
//    for (int i = column, j = row; j < n && i >= 0; i--, j++) {
//        if (i == column && j == row)
//            continue;
//        chess[i][j]++;
//    }
//    for (int i = column, j = row; i < n && j >= n; ++i, j--) {
//        if (i == column && j == row)
//            continue;
//        chess[i][j]++;
//    }
//    for (int i = column, j = row; i < n && j < n; ++i, j++) {
//        if (i == column && j == row)
//            continue;
//        chess[i][j]++;
//    }
//}
//
//void cancel(int column, int row, int n) {
//    for (int i = 0; i < n; ++i) {
//        if (i != column)
//            chess[i][row]--;
//    }
//    for (int i = column, j = row; i >= 0 && j >= 0; --i, j--) {
//        if (i == column && j == row)
//            continue;
//        chess[i][j]--;
//    }
//    for (int i = column, j = row; j < n && i >= 0; i--, j++) {
//        if (i == column && j == row)
//            continue;
//        chess[i][j]--;
//    }
//    for (int i = column, j = row; i < n && j >= n; ++i, j--) {
//        if (i == column && j == row)
//            continue;
//        chess[i][j]--;
//    }
//    for (int i = column, j = row; i < n && j < n; ++i, j++) {
//        if (i == column && j == row)
//            continue;
//        chess[i][j]--;
//    }
//}
//
//bool check(int column, int row, int n) {
//    //垂直
//    for (int i = 0; i < column; ++i) {
//        if (chess[i][row]) {
//            return false;
//        }
//    }
//
//    //主对角线
//    for (int i = column, j = row; j >= 0 && i >= 0; --j, --i) {
//        if (chess[i][j]) {
//            return false;
//        }
//    }
//
//    //斜对角线
//    for (int i = column, j = row; i >= 0 && j < n; i--, j++) {
//        if (chess[i][j]) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    findQueue(0, n);
//    cout << number;
//}
#include <iostream>

#define MAX 1000
using namespace std;
int a[MAX], b[MAX], c[MAX], d[MAX], n, s;

void print() {
    int i;
    s++;
    if (s <= 3) {
        for (i = 1; i <= n; i++)cout << a[i] << " ";
        cout << endl;
    }
}

int search(int i) {
    int j;
    for (j = 1; j <= n; j++)
        if (b[j] == 0 && c[i + j] == 0 && d[i - j + n] == 0) {
            a[i] = j;
            b[j] = 1;
            c[i + j] = 1;
            d[i - j + n] = 1;
            if (i == n)print();
            else search(i + 1);
            b[j] = 0;
            c[i + j] = 0;
            d[i - j + n] = 0;
        }
    return 0;
}

int main() {
    cin >> n;
    search(1);
    cout << s << endl;
    return 0;
}