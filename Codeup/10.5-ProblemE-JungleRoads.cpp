//
// Created by GreenArrow on 2020/3/1.
//
#include <iostream>
#include <climits>
#include <algorithm>

#define MAX 110
using namespace std;
typedef struct node {
    int u, v;
    int weight;
} *Node, node;
Node edges[MAX];
int father[MAX];

void init() {
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
    int edges_num = 0;
    sort(edges, edges + M, cmp);
    for (int i = 0; i < M; ++i) {
        int faA = findFather(edges[i]->u);
        int faB = findFather(edges[i]->v);
        if (faA != faB) {
            edges_num++;
            father[faA] = faB;
            ans += edges[i]->weight;
        }
        if (edges_num == N - 1) {
            break;
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
        if (N == 0)
            return 0;
        int index = 0;
        init();
        for (int i = 0; i < N - 1; ++i) {
            char u;
            int num;
            cin >> u >> num;
            for (int j = 0; j < num; ++j) {
                char v;
                int weight;
                cin >> v >> weight;

                Node newNode = new node;
                newNode->u = u - 'A';
                newNode->v = v - 'A';
                newNode->weight = weight;

                edges[index++] = newNode;

            }
        }

        cout << kruskal(N, index) << endl;


    }
}