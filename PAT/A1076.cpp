//
// Created by GreenArrow on 2020/3/19.
//
#include <iostream>
#include <vector>
#include <queue>

#define MAX 1010
using namespace std;

bool visited[MAX];
int layer[MAX] = {0};

int BFS(int s, int L, vector<int> graph[MAX]) {
    fill(visited, visited + MAX, false);
    fill(layer, layer + MAX, 0);
    int number = 0;
    layer[s] = 0;
    visited[s] = true;
    queue<int> Queue;
    Queue.push(s);
    while (!Queue.empty()) {
        int cur = Queue.front();
        Queue.pop();
        if (layer[cur] <= L && cur != s) {
            number++;
        }
        for (int i = 0; i < graph[cur].size(); ++i) {
            int v = graph[cur][i];
            if (!visited[graph[cur][i]]) {
                Queue.push(graph[cur][i]);
                layer[graph[cur][i]] = layer[cur] + 1;
                visited[graph[cur][i]] = true;
            }
        }
    }

    return number;
}

int main() {
    int n, L;
    vector<int> graph[MAX];
    cin >> n >> L;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int b;
            cin >> b;
            graph[b].push_back(i);
        }
    }

    int k;
    cin >> k;
    for (int l = 0; l < k; ++l) {
        int A;
        cin >> A;
        cout << BFS(A, L, graph) << endl;
    }

}