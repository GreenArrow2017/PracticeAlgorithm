//
// Created by GreenArrow on 2020/3/24.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> result;
int sum = -1;
vector<int> numString(10001, 0);
int arr[10010];
int N, K, P;


int kpow(int x, int y) {
    int ret = x;
    while (--y) {
        ret *= x;
    }
    return ret;
}

void DFS(int i, int sumPre, int depth, int tempSum) {
    if (depth == K) {
        if (sumPre == N) {

            if (sum < tempSum) {
                sum = tempSum;
                result.assign(numString.begin(), numString.begin() + K);

            }
        }
        return;
    }

    if (sumPre >= N || depth > K) {
        return;
    }

    for (; i >= 1; --i) {
        if (sumPre + arr[i] <= N) {
            numString[depth] = i;
            DFS(i, sumPre + arr[i], depth + 1, tempSum + i);
        }
    }

}


int tempMax = 0;

void init(int n, int p) {
    for (int i = 0; i <= n; i++) {
        int temp = kpow(i, p);
        if (temp > n) {
            break;
        }
        arr[i] = temp;
    }

    double num = (n - (K - 1));
    double kDouble = P;
    tempMax = pow(num, 1 / kDouble);

}

int main() {
    cin >> N >> K >> P;


    if (N == K) {
        cout << N << " = ";
        for (int i = 0; i < K; ++i) {
            cout << 1 << "^" << P;
            if (i != K - 1) {
                cout << " + ";
            }
        }
        return 0;
    }

    init(N, P);

    for (int i = tempMax; i >= 1; --i) {
        DFS(i, 0, 0, 0);
    }

    if (result.size() == 0) {
        cout << "Impossible";
        return 0;
    }

    cout << N << " = ";

    for (int j = 0; j < K; ++j) {
        cout << result[j] << "^" << P;
        if (j != K - 1) {
            cout << " + ";
        }
    }
}
