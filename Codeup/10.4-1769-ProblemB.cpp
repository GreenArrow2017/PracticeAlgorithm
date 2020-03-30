//
// Created by GreenArrow on 2020/2/27.
//
#include <iostream>

#define MAX 80
#define INF 1000000
using namespace std;

int G[MAX][MAX];

void Floyd(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if (G[i][k] != INF && G[k][j] != INF && G[i][j] > G[i][k] + G[k][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }

            }
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> G[i][j];
                if (i != j && G[i][j] == 0) {
                    G[i][j] = INF;
                }
            }
        }

        Floyd(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ((G[i][j] == INF) ? -1 : G[i][j]) << " ";
            }
            cout << endl;
        }

    }
}