//
// Created by GreenArrow on 2020/7/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:

    vector<bool> visited;
    vector<pair<double, int>> Graph[10005];
    vector<double> possibility;

    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
        visited.resize(n);
        possibility.resize(n);


        for (int i = 0; i < edges.size(); i++) {
            Graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            Graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        dfs(start, n);

//        for (int i = 0; i < possibility.size(); i++) {
//            cout << possibility[i] << " ";
//        }
//        cout << endl;

        return possibility[end] == INT_MIN ? 0.0 : possibility[end];

    }

    void dfs(int v, int n) {
        priority_queue<pair<double, int>> q;
        fill(possibility.begin(), possibility.end(), INT_MIN);
        possibility[v] = 1;
        q.push({possibility[v], v});
        while (!q.empty()) {

            double p = q.top().first;
            int u = q.top().second;
            q.pop();

            //cout << p << " " << u << endl;

            if (u == -1) {
                return;
            }

            if (visited[u]) {
                continue;
            }

            visited[u] = true;

            for (int j = 0; j < Graph[u].size(); j++) {
                double possi = Graph[u][j].first;
                int next = Graph[u][j].second;
                if (!visited[next]) {
                    if (possibility[u] != INT_MIN && possibility[u] * possi > possibility[next]) {
                        possibility[next] = possibility[u] * possi;
                        q.push({possibility[next], next});
                    }
                }
            }

        }

    }
};

int main() {


    vector<vector<int>> test = {{2, 3},
                                {1, 2},
                                {3, 4},
                                {1, 3},
                                {1, 4},
                                {0, 1},
                                {2, 4},
                                {0, 4},
                                {0, 2}};
    vector<double> edges = {0.06, 0.26, 0.49, 0.25, 0.2, 0.64, 0.23, 0.21, 0.77};
    Solution solution;
    cout << solution.maxProbability(5, test, edges, 0, 3);

}