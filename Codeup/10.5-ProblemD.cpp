//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>
#include <climits>
#include <algorithm>

#define MAX 5000

using namespace std;
typedef struct node {
    int u, v;
    int weight;
    bool flag = false;
} *Node, node;
Node edges[MAX];
int d[MAX];
int father[MAX];
int edges_num = 0;

void init() {
    edges_num = 0;
    fill(d, d + MAX, INT_MAX);
    for (int i = 0; i < MAX; ++i) {
        father[i] = i;
    }
}

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

bool cmp(Node a, Node b) {
    return a->weight < b->weight;
}

int kruskal(int N, int M) {
    int ans = 0;
    sort(edges, edges + M, cmp);
    for (int i = 0; i < M; ++i) {
        int faA = findFather(edges[i]->u);
        int faB = findFather(edges[i]->v);
        if (faA != faB) {
            edges_num++;
            father[faA] = faB;
            if (!edges[i]->flag) {
                ans += edges[i]->weight;
                edges[i]->flag = true;
            }
            if (edges_num == N - 1) {
                break;
            }
        }
    }
    if (edges_num != N - 1) {
        return -1;
    } else
        return ans;
}

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) {
            return 0;
        }
        int M = N * (N - 1) / 2;
        init();
        for (int i = 0; i < M; ++i) {
            int a, b, weight, flag;
            cin >> a >> b >> weight >> flag;
            Node newNode = new node;
            newNode->u = a;
            newNode->v = b;
            newNode->weight = weight;
            newNode->flag = flag;
            edges[i] = newNode;

            if (flag) {
                int faA = findFather(a);
                int faB = findFather(b);
                if (faA != faB) {
                    father[faA] = faB;
                    edges_num++;
                }
            }

        }

        if (edges_num == N - 1) {
            cout << "0" << endl;
        } else if (edges_num != N - 1) {
            int result = kruskal(N, M);
            cout << result << endl;
        }
    }
}