//
// Created by GreenArrow on 2020/2/7.
//

#include <iostream>
#include <stdio.h>
#include <iomanip>

#define MIN -2147483648

using namespace std;

bool Iflag[5] = {false};

int A1(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 5 == 0) {
            if (arr[i] % 2 == 0) {
                Iflag[0] = true;
                sum += arr[i];
            }
        }
    }
    return sum;
}

int A2(int *arr, int n) {
    int sum = 0;
    int flag = 1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 5 == 1) {
            Iflag[1] = true;
            sum += (arr[i] * flag);
            flag *= -1;
        }
    }
    return sum;
}

int A3(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 5 == 2) {
            Iflag[2] = true;
            sum++;
        }
    }
    return sum;
}

double A4(int *arr, int n) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 5 == 3) {
            Iflag[3] = true;
            sum += arr[i];
            count++;
        }
    }
    return sum / count;
}

int A5(int *arr, int n) {
    int max = MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 5 == 4) {
            Iflag[4] = true;
            if (max < arr[i]) {
                max = arr[i];
            }
        }
    }
    return max;
}

int main() {
    int arr[100000];
    int index;
    cin >> index;
    cin.ignore();
    for (int i = 0; i < index; ++i) {
        cin >> arr[i];
    }

    A1(arr, index);
    A2(arr, index);
    A3(arr, index);
    A4(arr, index);
    A5(arr, index);

    if (Iflag[0]) {
        cout << A1(arr, index);
    } else {
        cout << 'N';
    }
    cout << " ";


    if (Iflag[1]) {
        cout << A2(arr, index);
    } else {
        cout << 'N';
    }
    cout << " ";


    if (Iflag[2]) {
        cout << setiosflags(ios::fixed) << setprecision(1);
        cout << A3(arr, index);
        //printf("%.1d", A3(arr, index));
    } else {
        cout << 'N';
    }
    cout << " ";


    if (Iflag[3]) {
        cout << A4(arr, index);
    } else {
        cout << 'N';
    }
    cout << " ";

    if (Iflag[4]) {
        cout << A5(arr, index);
    } else {
        cout << 'N';
    }
}

