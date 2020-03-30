//
// Created by GreenArrow on 2020/3/7.
//
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

#define MAX 10000
using namespace std;

typedef struct node {
    int u;
    int weight;
} node;

vector<node> Nodes[MAX];
bool visited[MAX];
int d[MAX];

int prim(int n, int &number) {

    int max = INT_MIN;

    fill(d, d + MAX, INT_MAX);
    fill(visited, visited + MAX, false);

    d[1] = 0;


    for (int i = 1; i <= n; ++i) {

        int u = -1;
        int MIN = INT_MAX;

        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && MIN > d[j]) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) {
            return -1;
        }

        if (max < d[u]) {
            max = d[u];
        }
        visited[u] = true;

        for (int k = 0; k < Nodes[u].size(); ++k) {
            node cur = Nodes[u][k];
            int v = cur.u;
            if (!visited[v] && d[v] > cur.weight) {
                d[v] = cur.weight;
            }
        }

    }
    return max;

}

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, weight;
        cin >> a >> b >> weight;
        node u;
        u.u = a;
        u.weight = weight;
        Nodes[b].push_back(u);

        node v;
        v.u = b;
        v.weight = weight;
        Nodes[a].push_back(v);
    }


    int num = 0;
    int ans = prim(n, num);
    cout << n - 1 << " " << ans << endl;

}