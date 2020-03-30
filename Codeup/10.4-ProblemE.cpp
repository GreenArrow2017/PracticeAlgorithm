//
// Created by GreenArrow on 2020/2/29.
//
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX 1010
using namespace std;

typedef struct node {
    int v;
    int weight;
    int price;
} *Node, node;
vector<Node> adj[MAX];
bool visited[MAX] = {false};
typedef struct distanceAndPrice {
    int distance;
    int price;



} *dap, distanceAndPrice;

distanceAndPrice d[MAX];

void Dijkstra(int n, int s) {

    for (int i = 0; i < MAX; ++i) {
        d[i].distance = INT_MAX;
        d[i].price = INT_MAX;
    }

    fill(visited, visited + MAX, false);

    d[s].distance = 0;
    d[s].price = 0;

    for (int j = 1; j <= n; ++j) {

        int u = -1;
        int MIN = INT_MAX;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (d[i].distance < MIN)) {
                u = i;
                MIN = d[i].distance;
            }
        }

        if (u == -1) {
            return;
        }

        visited[u] = true;

        for (int k = 0; k < adj[u].size(); ++k) {
            Node v = adj[u][k];
            if (!visited[v->v]) {
                if (v->weight + d[u].distance < d[v->v].distance) {
                    d[v->v].distance = v->weight + d[u].distance;
                    d[v->v].price = v->price + d[u].price;
                } else if (v->weight + d[u].distance == d[v->v].distance && v->price + d[u].price < d[v->v].price) {
                    d[v->v].price = v->price + d[u].price;
                }
            }
        }

    }

}

int main() {

    int N, M;
    while (cin >> N >> M) {
        cin.ignore();

        for (auto &j : adj) {
            j.clear();
        }

        if (N == 0) {
            return 0;
        }
        for (int i = 0; i < M; ++i) {
            int a, b, weight, price;
            cin >> a >> b >> weight >> price;
            cin.ignore();



            Node A = new node;
            A->v = a;
            A->weight = weight;
            A->price = price;
            adj[b].push_back(A);

            Node B = new node;
            B->v = b;
            B->weight = weight;
            B->price = price;
            adj[a].push_back(B);

        }

        int s, t;
        cin >> s >> t;

        Dijkstra(N, s);

        cout << d[t].distance << " " << d[t].price << endl;

    }

}