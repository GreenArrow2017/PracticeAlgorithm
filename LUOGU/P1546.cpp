//
// Created by GreenArrow on 2020/3/7.
//
#include <iostream>
#include <climits>
#include <algorithm>

#define MAX 110
using namespace std;

int chess[MAX][MAX];
int d[MAX];
bool visited[MAX];

int prim(int n) {

    fill(visited, visited + MAX, false);
    fill(d, d + MAX, INT_MAX);

    d[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && MIN > d[j]) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) {
            return -1;
        }

        visited[u] = true;
        ans += d[u];

        for (int k = 0; k < n; ++k) {
            if (!visited[k] && d[k] > chess[u][k]) {
                d[k] = chess[u][k];
            }
        }
    }

    return ans;

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> chess[i][j];
        }
    }

    cout << prim(n);

}
