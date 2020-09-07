//
// Created by GreenArrow on 2020/7/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<bool> visited;
    vector<vector<int>> graph;
    int makeConnected(int n, vector<vector<int>> &connections) {


        if (connections.size() < n - 1) {
            return -1;
        }

        graph.resize(n);

        for (int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }

        int count = 0;

        visited.resize(n);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }
        return count-1;
    }

    void dfs(int v) {
        visited[v] = true;
        for (int i = 0; i < graph[v].size(); i++) {
            if (!visited[graph[v][i]]) {
                dfs(graph[v][i]);
            }
        }
    }
};
