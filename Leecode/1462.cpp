//
// Created by GreenArrow on 2020/7/31.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 105
using namespace std;

class Solution {
public:

    int memory[MAX][MAX] = {-1};

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector<bool> result;
        for (int i = 0; i < MAX; i++) {
            fill(memory[i], memory[i] + MAX, -1);
        }
        vector<vector<int>> graph(n);
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < queries.size(); i++) {
            result.push_back(dfs(queries[i][0], queries[i][1], graph));
        }
        return result;
    }

    bool dfs(int start, int end, vector<vector<int>> &graph) {
        if (start == end) {
            memory[start][end] = true;
            return true;
        }

        if (memory[start][end] != -1) {
            return memory[start][end];
        }

        for (int i = 0; i < graph[start].size(); i++) {
            if (dfs(graph[start][i], end, graph)) {
                memory[graph[start][i]][end] = 1;
                return memory[graph[start][i]][end];
            }
        }
        memory[start][end] = 0;
        return false;
    }
};