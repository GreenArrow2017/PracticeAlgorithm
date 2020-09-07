//
// Created by root on 2020/8/8.
//
#include <iostream>
#include <cstring>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<bool> visited;
    vector<int> distance;
    int direction[4][2] = {{0,  1},
                           {0,  -1},
                           {1,  0},
                           {-1, 0}};

    int maxDistance(vector<vector<int>> &grid) {

        visited.resize(grid.size() * grid[0].size());
        distance.resize(grid.size() * grid[0].size());
        int nRow = grid.size();
        int nColumn = grid[0].size();

        fill(visited.begin(), visited.end(), false);
        fill(distance.begin(), distance.end(), false);
        queue<pair<int, int>> q;

        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nColumn; j++) {

                if (grid[i][j]) {
                    q.push({i, j});
                }

            }
        }
        int MAX = -1;
        while (!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;

            q.pop();
            visited[x * nRow + y] = true;


            for (int i = 0; i < 4; i++) {
                int x_next = x + direction[i][0], y_next = y + direction[i][1];
                if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn &&
                    !visited[x_next * nRow + y_next]) {
                    if (grid[x][y] && !grid[x_next][y_next]) {
                        distance[x_next * nRow + y_next] = distance[x * nRow + y] + 1;
                        MAX = max(MAX, distance[x_next * nRow + y_next]);
                        visited[x_next * nRow + y_next] = true;
                    } else if (!grid[x][y] && !grid[x_next][y_next]) {
                        distance[x_next * nRow + y_next] = distance[x * nRow + y] + 1;
                        MAX = max(MAX, distance[x_next * nRow + y_next]);
                        visited[x_next * nRow + y_next] = true;
                    }
                    if (!grid[x_next][y_next])
                        q.push({x_next, y_next});
                }
            }
        }
        return MAX;
    }

};

int main() {
    Solution solution;
    vector<vector<int>> test = {{0, 0, 1, 1, 1},
                                {0, 1, 1, 0, 0},
                                {0, 0, 1, 1, 0},
                                {1, 0, 0, 0, 0},
                                {1, 1, 0, 0, 1}};
    solution.maxDistance(test);

    for (int i = 0; i < solution.distance.size(); i++) {
        cout << solution.distance[i] << " ";
    }
}
//2 1 0 0 0
//1 0 0 1 2
//2 1 0 0 3
//0 2 1 2 3
//0 0 2 3 0