//
// Created by GreenArrow on 2020/3/18.
//
#include <iostream>
#include <climits>
#include <algorithm>

#define MAX 510
using namespace std;

class edge {
public:
    int distance;
    int cost;

    edge(int distance, int cost) {
        this->distance = distance;
        this->cost = cost;
    }

    edge() {

    }
};

edge map[MAX][MAX];
edge d[MAX];
bool visited[MAX];
int path[MAX];

void print_path(int s, int ed) {
    if (s != ed) {
        print_path(s, path[ed]);
        cout << ed << " ";
    }
    if (s == ed) {
        cout << s << " ";
    }
}

void Dijiskra(int s, int n) {
    fill(visited, visited + MAX, false);
    fill(d, d + MAX, edge(INT_MAX, INT_MAX));
    d[s].distance = 0;
    d[s].cost = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        int min = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && d[j].distance < min) {
                min = d[j].distance;
                u = j;
            }
        }
        if (u == -1) {
            return;
        }

        visited[u] = true;
        for (int k = 0; k < n; ++k) {
            if (!visited[k] && map[u][k].distance != INT_MAX) {
                if (d[k].distance > d[u].distance + map[u][k].distance) {
                    d[k].distance = d[u].distance + map[u][k].distance;
                    d[k].cost = d[u].cost + map[u][k].cost;
                    path[k] = u;
                } else if (d[k].distance == d[u].distance + map[u][k].distance) {
                    if (d[k].cost > d[u].cost + map[u][k].cost) {
                        d[k].distance = d[u].distance + map[u][k].distance;
                        d[k].cost = d[u].cost + map[u][k].cost;
                        path[k] = u;
                    }
                }
            }
        }
    }
}

int main() {
    fill(map[0], map[0] + MAX * MAX, edge(INT_MAX, INT_MAX));
    int vertex_n, m, s, ed;
    cin >> vertex_n >> m >> s >> ed;
    for (int i = 0; i < m; ++i) {
        int a, b, weight, cost;
        cin >> a >> b >> weight >> cost;
        map[a][b] = edge(weight, cost);
        map[b][a] = edge(weight, cost);
    }

    Dijiskra(s, vertex_n);

    print_path(s, ed);

    cout << d[ed].distance << " " << d[ed].cost;

}
