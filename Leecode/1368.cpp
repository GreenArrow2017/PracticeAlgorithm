//
// Created by GreenArrow on 2020/8/28.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    int direction[5][2] = {{0,  0},
                           {0,  1},
                           {0,  -1},
                           {1,  0},
                           {-1, 0}};

    int minCost(vector<vector<int>> &grid) {
        int nRow = grid.size();
        int nColumn = grid[0].size();

        vector<bool> visited(nRow * nColumn, false);

        vector<int> distance(nRow * nColumn, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int dist = q.top().first;
            int current = q.top().second;
            q.pop();
            if (visited[current]) {
                continue;
            }
            distance[current] = dist;
            visited[current] = true;
            int x = current / nColumn;
            int y = current % nColumn;
            for (int i = 1; i <= 4; i++) {
                int x_next = x + direction[i][0];
                int y_next = y + direction[i][1];
                int next_dist = dist;
                if (i != grid[x][y]) {
                    next_dist++;
                }
                if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn &&
                    next_dist < distance[x_next * nColumn + y_next]) {
                    distance[x_next * nColumn + y_next] = next_dist;
                    q.push({next_dist, x_next * nColumn + y_next});
                }
            }
        }

        return distance[nRow * nColumn - 1];
    }
};