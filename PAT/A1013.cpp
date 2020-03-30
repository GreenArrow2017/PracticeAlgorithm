//
// Created by GreenArrow on 2020/3/16.
//
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001
using namespace std;

vector<int> graph[MAX];


bool visited[MAX];

void BFS(int v, int city) {
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        if (!visited[graph[v][i]]) {
            BFS(graph[v][i], city);
        }
    }
}

int main() {
    int N, M, K;


    scanf("%d %d %d", &N, &M, &K);

    for (int j = 0; j < M; ++j) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int k = 0; k < K; ++k) {
        fill(visited, visited + N + 1, false);
        int city;
        scanf("%d", &city);

        visited[city] = true;
        int index = 0;
        for (int l = 1; l <= N; ++l) {
            if (!visited[l]) {
                BFS(l, city);
                index++;
            }
        }

        cout << index - 1 << endl;

    }

}
