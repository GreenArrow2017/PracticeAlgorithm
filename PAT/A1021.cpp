//
// Created by GreenArrow on 2020/3/17.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX 10010
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];

int max_BFS = INT_MIN;

void BFS(int v, int depth) {
    visited[v] = true;


    bool flag = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        int u = graph[v][i];
        if (!visited[u]) {
            flag = false;
            BFS(u, depth + 1);
        }
    }

    if (flag) {
        if (max_BFS < depth) {
            max_BFS = depth;
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> nodes;
    int max = INT_MIN;
    int index_ = 0;
    bool flag = false;
    for (int j = 1; j <= N; ++j) {
        fill(visited, visited + N + 1, false);
        max_BFS = INT_MIN;
        BFS(j, 0);
        //cout << max_BFS << endl;
        index_++;
        if (!flag)
            for (int i = 1; i <= N; ++i) {
                if (!visited[i]) {
                    flag = true;
                    //不联通
                    for (int k = j + 1; k <= N; ++k) {
                        if (!visited[k]) {
                            BFS(k, 0);
                            index_++;
                        }

                        bool connected = true;

                        for (int l = 1; l <= N; ++l) {
                            if (!visited[l]) {
                                connected = false;
                                break;
                            }
                        }

                        if (connected) {
                            cout << "Error: " << index_ << " components" << endl;
                            return 0;
                        }

                    }

                }
            }

        if (max_BFS > max) {
            max = max_BFS;
            nodes.clear();
            nodes.push_back(j);
        } else if (max_BFS == max) {
            nodes.push_back(j);
        }
    }

    sort(nodes.begin(), nodes.end());

    for (int m = 0; m < nodes.size(); ++m) {
        cout << nodes[m] << endl;
    }
}
