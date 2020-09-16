//
// Created by GreenArrow on 2020/7/27.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:


    vector<pair<int, int>> node_in_out;

    vector<vector<int>> Graph;

    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {

        vector<int> result;

        int n = graph.size();

        queue<int> q;

        node_in_out.resize(n);
        Graph.resize(n);

        for (int i = 0; i < n; i++) {
            node_in_out[i] = {0, 0};
        }

        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                Graph[graph[i][j]].push_back(i);
                node_in_out[graph[i][j]].second++;
                node_in_out[i].first++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (node_in_out[i].first == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {

            int current = q.front();
            q.pop();
            result.push_back(current);
            for (int i = 0; i < Graph[current].size(); i++) {
                int w = Graph[current][i];
                node_in_out[current].second--;
                node_in_out[w].first--;
                if(node_in_out[w].first == 0){
                    q.push(w);
                }
            }
        }

        sort(result.begin(), result.end());

        return result;
    }


};
