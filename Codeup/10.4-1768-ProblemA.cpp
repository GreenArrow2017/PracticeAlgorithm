//
// Created by GreenArrow on 2020/2/26.
//
#include <iostream>
#include <algorithm>

#define MAX 1000
#define INF 100000000
using namespace std;
bool visited[MAX] = {false};
int n, m, s, G[MAX][MAX];
int d[MAX] = {INF};

void print_G() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void Dijkstra(int s) {
    fill(d, d + MAX, INF);
    fill(visited, visited + MAX, false);
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) {
            return;
        }

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main() {

    while (cin >> n >> s) {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> G[i][j];
                if (i != j && G[i][j] == 0) {
                    G[i][j] = INF;
                }
            }
        }

        //print_G();
        Dijkstra(s);

        for (int k = 0; k < n; ++k) {
            if (k != s && d[k] != INF)
                cout << d[k] << " ";
            else if (k != s && d[k] == INF)
                cout << "-1" << " ";
        }
        cout << endl;

    }

    return 0;
}