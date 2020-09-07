//
// Created by GreenArrow on 2020/7/27.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

class Solution {
public:

    vector<bool> visited;
    vector<vector<int>> Graph;
    vector<int> dist;

    int networkDelayTime(vector<vector<int>> &times, int N, int K) {

        visited.resize(N);
        Graph.resize(N);
        dist.resize(N);

        for (int i = 0; i < N; i++) {
            Graph[i].resize(N);
            fill(Graph[i].begin(), Graph[i].end(), -1);
        }

        for (int i = 0; i < times.size(); i++) {
            Graph[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }


        Dijistra(--K, N);
        int MAX = INT_MIN;
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            if (dist[i] > MAX) {
                MAX = dist[i];
            }
        }

        return MAX;
    }

    void Dijistra(int v, int N) {
        for (int i = 0; i < N; i++) {
            dist[i] = INT_MAX;
        }
        dist[v] = 0;
        for (int i = 0; i < N; i++) {
            int MIN = INT_MAX;
            int u = -1;
            for (int j = 0; j < N; j++) {
                if (!visited[j] && MIN > dist[j]) {
                    MIN = dist[j];
                    u = j;
                }
            }
            if(u == -1){
                return;
            }

            visited[u] = true;
            for (int k = 0; k < N; k++) {
                if (!visited[k] && Graph[u][k] != -1 && dist[u] + Graph[u][k] < dist[k]) {
                    dist[k] = dist[u] + Graph[u][k];
                }
            }
        }
    }

};

int main() {

    vector<vector<int>> test = {
            {2, 1, 1},
            {2, 3, 1},
            {3, 4, 1}
    };
    Solution solution;
    solution.networkDelayTime(test, 4, 2);
}