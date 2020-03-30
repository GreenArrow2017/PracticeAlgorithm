//
// Created by GreenArrow on 2020/2/29.
//
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX 110
using namespace std;

typedef struct node {
    int v;
    int weight;
} node, *Node;
vector<Node> adj[MAX];
bool visited[MAX] = {false};
int d[MAX] = {0};

int prim(int n, int s) {
    fill(visited, visited + MAX, false);
    fill(d, d + MAX, INT_MAX);
    int ans = 0;
    d[s] = 0;
    for (int i = 1; i <= n; ++i) {
        int u = -1;
        int MIN = INT_MAX;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && MIN > d[j]) {
                MIN = d[j];
                u = j;
            }
        }

        if (u == -1) {
            return -1;
        }

        visited[u] = true;
        ans += d[u];
        for (int k = 0; k < adj[u].size(); ++k) {
            int v = adj[u][k]->v;
            if (!visited[v] && adj[u][k]->weight < d[v]) {
                d[v] = adj[u][k]->weight;
            }
        }

    }
    return ans;
}

int main() {

    int N;
    while (cin >> N) {
        cin.ignore();
        if (N == 0) {
            return 0;
        }
        for (auto &i : adj) {
            i.clear();
        }

        int a, b, weight;
        for (int j = 0; j < (N * (N - 1)) / 2; ++j) {

            cin >> a >> b >> weight;
            cin.ignore();

            Node A = new node;
            A->v = a;
            A->weight = weight;
            adj[b].push_back(A);

            Node B = new node;
            B->v = b;
            B->weight = weight;
            adj[a].push_back(B);
        }

        cout << prim(N, 1) << endl;

    }

}
