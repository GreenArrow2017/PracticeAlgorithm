//
// Created by GreenArrow on 2020/9/11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<bool> visited;
    vector<vector<int>> G;

    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target) {
        visited.resize(n);
        G.resize(n);
        for (int i = 0; i < graph.size(); i++) {
            G[graph[i][0]].push_back(graph[i][1]);
        }

        dfs(start, target);
        return visited[target];

    }

    void dfs(int v, int target) {
        visited[v] = true;
        if (v == target) {
            return;
        }
        for (int i = 0; i < G[v].size(); i++) {
            if (!visited[G[v][i]]) {
                dfs(G[v][i], target);
            }
        }
    }
};