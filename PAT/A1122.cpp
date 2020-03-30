//
// Created by GreenArrow on 2020/3/16.
//
#include <iostream>
#include <algorithm>

using namespace std;
int chess[202][202];

bool Hamilton(int n, int *array, int vertex_n) {
    if (vertex_n + 1 != n) {
        return false;
    }

    bool visited[vertex_n + 1];
    fill(visited + 1, visited + vertex_n + 1, false);

    int pre = array[1];
    visited[pre] = true;
    for (int i = 2; i <= n; ++i) {
        if (chess[pre][array[i]] != 1 && chess[array[i]][pre] != 1 && array[i] != pre) {
            return false;
        }
        pre = array[i];
        visited[pre] = true;
    }

    for (int j = 1; j <= vertex_n; ++j) {
        if (!visited[j]) {
            return false;
        }
    }

    if (array[1] != array[n]) {
        return false;
    }

    return true;
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 2; ++i) {
        fill(chess[i], chess[i] + n + 2, 0);
    }
    for (int j = 0; j < m; ++j) {
        int a, b;
        cin >> a >> b;
        chess[a][b] = 1;
        chess[b][a] = 1;
    }

    int k;
    cin >> k;
    for (int l = 0; l < k; ++l) {
        int adjectN;
        cin >> adjectN;
        int array[adjectN + 10];
        for (int i = 1; i <= adjectN; ++i) {
            cin >> array[i];
        }

        if (Hamilton(adjectN, array, n)) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
    }
}
