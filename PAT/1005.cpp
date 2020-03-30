//
// Created by GreenArrow on 2020/2/5.
//

#include <iostream>
#include <algorithm>
using namespace std;
int num[10000] = {0};

void setNum(int n) {
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            num[n]++;
        } else {
            n = (n * 3 + 1) / 2;
            num[n]++;
        }
    }
}

bool cmp(int a,int b)
{
    return a>b;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        setNum(arr[i]);
    }
    int result[n];
    int number = 0;
    for (int j = n-1; j >=0; --j) {
        if (num[arr[j]] == 0){
            result[number++] = arr[j];
        }
    }
    sort(result, result+ number, cmp);
    for (int k = 0; k < number; ++k) {
        cout << result[k];
        if (k != (number-1)){
            cout << " ";
        }
    }
}

