//
// Created by GreenArrow on 2020/8/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<int> result;
        vector<int> nodes(n);
        vector<int> Depths(n);
        vector<vector<int>> Graph(n);
        for (int i = 0; i < edges.size(); i++) {
            nodes[edges[i][0]]++;
            nodes[edges[i][1]]++;
            Graph[edges[i][0]].push_back(edges[i][1]);
            Graph[edges[i][1]].push_back(edges[i][0]);
        }

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (nodes[i] == 1) {
                q.push({0, i});
            }
        }

        int maxDepth = 0;

        while (!q.empty()) {

            int depth = q.front().first;
            int v = q.front().second;
            q.pop();
            Depths[v] = depth;
            maxDepth = depth;
            nodes[v]--;
            for (int i = 0; i < Graph[v].size(); i++) {
                nodes[Graph[v][i]]--;
                if (nodes[Graph[v][i]] == 1) {
                    q.push({depth + 1, Graph[v][i]});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if(Depths[i] == maxDepth){
                result.push_back(i);
            }
        }

        return result;

    }
};