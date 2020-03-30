//
// Created by GreenArrow on 2020/2/24.
//
#include <iostream>

using namespace std;

#define max 10010

int father[max];

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }

    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }

    return x;
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}

int main() {

    int N, M;
    while (cin >> N >> M) {

        cin.ignore();


        if (N == 0 && M == 0) {
            return 0;
        }

        for (int i = 1; i <= N; ++i) {
            father[i] = i;
        }

        for (int j = 0; j < M; ++j) {

            int a, b;
            cin >> a >> b;
            cin.ignore();

            Union(a, b);
        }

        int sum = 0;
        for (int k = 1; k <= N; ++k) {
            if (father[k] == k) {
                sum++;
            }
        }

        if (sum == 1 && M == N - 1) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;

    }

}
