//
// Created by GreenArrow on 2020/3/17.
//
#include <iostream>
#include <algorithm>
#include <climits>

#define MAX 510
using namespace std;

int chess[MAX][MAX];
int people[MAX];
int d[MAX];
bool visited[MAX];
int num[MAX];
int w[MAX];

void Dijikstra(int v, int n) {

    fill(d, d + MAX, INT_MAX);
    fill(visited, visited + MAX, false);
    fill(w, w + MAX, 0);
    fill(num, num + MAX, 0);
    w[v] = people[v];
    num[v] = 1;
    d[v] = 0;

    for (int i = 0; i < n; ++i) {
        int min = INT_MAX;
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && min > d[j]) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1)
            return;

        visited[u] = true;

        for (int k = 0; k < n; ++k) {
            if (!visited[k] && chess[u][k] != INT_MAX) {

                if (d[k] > d[u] + chess[u][k]) {
                    d[k] = d[u] + chess[u][k];
                    w[k] = w[u] + people[k];
                    num[k] = num[u];
                } else if (d[k] == d[u] + chess[u][k]) {
                    num[k] += num[u];
                    if (w[u] + people[k] > w[k]) {
                        w[k] = w[u] + people[k];
                    }
                }

            }
        }

    }

}

int main() {

    fill(chess[0], chess[0] + MAX * MAX, INT_MAX);

    int vertex_n, m;
    int s, end;
    cin >> vertex_n >> m >> s >> end;

    for (int j = 0; j < vertex_n; ++j) {
        cin >> people[j];
    }

    for (int k = 0; k < m; ++k) {
        int a, b, weight;
        cin >> a >> b >> weight;
        chess[a][b] = weight;
        chess[b][a] = weight;
    }

//    for (int i = 0; i < vertex_n; ++i) {
//        for (int j = 0; j < vertex_n; ++j) {
//            cout << ((chess[i][j] != INT_MAX) ? chess[i][j] : 0) << " ";
//        }
//        cout << endl;
//    }

    Dijikstra(s, vertex_n);

    cout << num[end] << " " << w[end];
}
