//
// Created by GreenArrow on 2020/2/28.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

#define MAX 1100

using namespace std;

int Graph[MAX][MAX];
int d[MAX];
int pre[MAX];
bool visited[MAX] = {false};

void print_Graph(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}

void init() {
    for (int i = 0; i < MAX; ++i) {
        fill(Graph[i], Graph[i] + MAX, INT_MAX);
    }
    for (int j = 0; j < MAX; ++j) {
        Graph[j][j] = 0;
    }
}

void Dijsktra(int n, int s) {

    fill(d, d + MAX, INT_MAX);
    fill(visited, visited + MAX, false);
    d[s] = 0;
    for (int i = 1; i <= n; ++i) {

        int u = -1, MIN = INT_MAX;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && MIN > d[j]) {
                MIN = d[j];
                u = j;
            }
        }

        if (u == -1) {
            return;
        }

        visited[u] = true;

        for (int k = 1; k <= n; ++k) {
            if ((!visited[k] && d[k] > d[u] + Graph[u][k]) ||
                (!visited[k] && d[k] == d[u] + Graph[u][k] && u < pre[k])) {
                d[k] = d[u] + Graph[u][k];
                pre[k] = u;
            }
        }

    }
}

void dfs(int s, int t) {
    if (s == t) {
        cout << s << " ";
        return;
    }
    dfs(s, pre[t]);
    cout << t << " ";
}

int main() {

    int n, m, s, t;
    while (cin >> n >> m >> s >> t) {

        init();

        for (int i = 0; i < m; ++i) {

            int a, b, w;
            cin >> a >> b >> w;
            Graph[a][b] = w;
            Graph[b][a] = w;

        }

        //print_Graph(n);

        Dijsktra(n, s);

        if (d[t] == INT_MAX) {
            cout << "can't arrive";
            continue;
        } else {
            cout << d[t] << endl;
            dfs(s, t);
        }
        cout << endl;

    }

}
/**
 *
3 3 2 1
1 3 3
1 2 1
2 3 1
**/