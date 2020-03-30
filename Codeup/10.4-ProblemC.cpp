//
// Created by GreenArrow on 2020/2/28.
//
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

#define MAX 110

using namespace std;
int Graph[MAX][MAX] = {0};
int d[MAX];
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
    for (int k = 0; k < MAX; ++k) {
        for (int i = 0; i < MAX; ++i) {
            Graph[k][i] = 0;
        }
    }
}

void Dijkstra(int N, int v) {
    fill(d, d + MAX, INT_MAX);
    fill(visited, visited + MAX, false);
    d[v] = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1;
        int MIN = INT_MAX;
        for (int j = 0; j < N; ++j) {
            if (!visited[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }

        if (u == -1) {
            return;
        }

        visited[u] = true;
        for (int k = 0; k < N; ++k) {
            if (!visited[k] && Graph[u][k] != INT_MAX && d[k] > d[u] + Graph[u][k]) {
                d[k] = d[u] + Graph[u][k];
            }
        }
    }
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        cin.ignore();

        init();

        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            cin.ignore();
            int weight = pow(2, i);
            Graph[a][b] = weight;
            Graph[b][a] = weight;
        }

        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                if (Graph[i][j] == 0 && i != j) {
                    Graph[i][j] = INT_MAX;
                }
            }
        }

        //print_Graph(N);


        Dijkstra(N, 0);
        for (int k = 1; k < N; ++k) {
            if (d[k] == INT_MAX) {
                cout << -1 << endl;
            } else {
                cout << d[k] % 100000 << endl;
            }
        }

    }

}
