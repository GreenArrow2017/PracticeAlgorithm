//
// Created by GreenArrow on 2020/2/29.
//
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#define MAX 110
using namespace std;

typedef struct node {
    int u, v;
    int weight;
} *Node, node;

vector<Node> adj[MAX];
int d[MAX];
bool visited[MAX];
Node E[MAX];
int father[MAX];

bool cmp(Node a, Node b) {
    return a->weight < b->weight;
}

int findFather(int a) {
    while (a != father[a]) {
        a = father[a];
    }
    return a;
}

int Kruskal(int n, int m) {
    int ans = 0;
    int Num_Edge = 0;
    sort(E, E + m, cmp);
    for (int i = 0; i < m; ++i) {
        int faU = findFather(E[i]->u);
        int faV = findFather(E[i]->v);
        if (faU != faV) {
            father[faU] = faV;
            ans += E[i]->weight;
            Num_Edge++;
            if (Num_Edge == n - 1)
                break;
        }
    }
    if (Num_Edge != n - 1) {
        return -1;
    } else
        return ans;
}

int main() {

    int M, N;
    while (cin >> M >> N) {
        cin.ignore();
        if (M == 0) {
            return 0;
        }

        for (int k = 0; k < MAX; ++k) {
            father[k] = k;
        }

        for (int j = 0; j < MAX; ++j) {
            adj[j].clear();
        }

        for (int i = 0; i < M; ++i) {
            Node edges = new node;
            int a, b, weight;
            cin >> a >> b >> weight;
            edges->u = a;
            edges->v = b;
            edges->weight = weight;
            E[i] = edges;
        }

        int result = Kruskal(N, M);
        if (result == -1) {
            cout << "?" << endl;
        } else
            cout << result << endl;

    }

}
