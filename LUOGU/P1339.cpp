//
// Created by GreenArrow on 2020/3/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define N 2600
#define M 6300
using namespace std;

typedef struct node {
    int u;
    int weight;
} *Node, node;

bool visited[N] = {false};
vector<node> Nodes[N];
int distances[N];

void Dijistrk(int n, int s) {

    fill(visited, visited + N, false);
    fill(distances, distances + N, INT_MAX);

    distances[s] = 0;


    for (int i = 1; i <= n; ++i) {

        int u = -1;
        int MIN = INT_MAX;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && MIN > distances[j]) {
                MIN = distances[j];
                u = j;
            }
        }

        if (u == -1) {
            return;
        }


        visited[u] = true;
        for (int k = 0; k < Nodes[u].size(); ++k) {
            int v = Nodes[u][k].u;
            if (!visited[v] && distances[v] > distances[u] + Nodes[u][k].weight) {
                distances[v] = distances[u] + Nodes[u][k].weight;
            }
        }

    }

}

int main() {

    int n, m, source, destination;
    cin >> n >> m >> source >> destination;

    for (int i = 0; i < m; ++i) {

        int a, b, weight;

        cin >> a >> b >> weight;

        node curA;
        curA.u = a;
        curA.weight = weight;
        Nodes[b].push_back(curA);

        node curB;
        curB.u = b;
        curB.weight = weight;
        Nodes[a].push_back(curB);
    }

    Dijistrk(n, source);
    cout << distances[destination];

}
