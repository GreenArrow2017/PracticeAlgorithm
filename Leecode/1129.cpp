//
// Created by GreenArrow on 2020/9/3.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:

    class edge {
    public:
        int b;
        // 1 is red, -1 is blue
        int color;

        edge(int b, int color) {
            this->b = b;
            this->color = color;
        }
    };

    int visited[101][101][2];
    vector<vector<edge>> graph;

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges) {
        graph.resize(n);
        for (vector<int> e : red_edges) {
            edge ed(e[1], 1);
            graph[e[0]].push_back(ed);
        }
        for (vector<int> e : blue_edges) {
            edge ed(e[1], -1);
            graph[e[0]].push_back(ed);
        }

        vector<int> result;
        result.resize(n);
        fill(result.begin(), result.end(), -1);
        result[0] = 0;

        queue<pair<pair<int, int>, edge>> q;
        for (int i = 0; i < graph[0].size(); i++) {
            q.push({{0, 1}, graph[0][i]});
            if (graph[0][i].color) {
                visited[0][graph[0][i].b][1] = 1;
                result[graph[0][i].b] = 1;
            } else {
                visited[0][graph[0][i].b][0] = 1;
                result[graph[0][i].b] = 1;
            }
        }
        while (!q.empty()) {
            int current = q.front().first.first;
            int depth = q.front().first.second;
            edge e = q.front().second;
            q.pop();
            for (int i = 0; i < graph[e.b].size(); i++) {
                edge next = graph[e.b][i];
                if (next.color == 1 && !visited[e.b][next.b][next.color] && e.color * next.color == -1) {
                    q.push({{e.b, depth + 1}, next});
                    visited[e.b][next.b][next.color] = 1;
                    if (result[next.b] == -1) {
                        result[next.b] = depth + 1;
                    }

                } else if (next.color == -1 && !visited[e.b][next.b][0] && e.color * next.color == -1) {
                    q.push({{e.b, depth + 1}, next});
                    visited[e.b][next.b][0] = 1;
                    if (result[next.b] == -1) {
                        result[next.b] = depth + 1;
                    }
                }
            }
        }
        result[0] = 0;
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> red = {{0, 1}};
    vector<vector<int>> blue = {{1, 2}};
    solution.shortestAlternatingPaths(3, red, blue);
}