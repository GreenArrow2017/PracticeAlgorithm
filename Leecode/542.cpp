//
// Created by GreenArrow on 2020/7/29.
//

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//class Solution {
//public:
//
//    int direction[4][2] = {{0,  1},
//                           {0,  -1},
//                           {1,  0},
//                           {-1, 0}};
//
//    bool visited[10000] = {false};
//
//    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
//
//        vector<vector<int>> copy;
//        copy.assign(matrix.begin(), matrix.end());
//        int nRow = matrix.size();
//        int nColumn = matrix[0].size();
//        for (int i = 0; i < nRow; i++) {
//            for (int j = 0; j < nColumn; j++) {
//                if (matrix[i][j] == 1) {
//                    fill(visited, visited + 10000, false);
//                    bfs(i, j, nRow, nColumn, matrix, copy);
//                }
//            }
//        }
//        return copy;
//    }
//
//    void bfs(int x, int y, int nRow, int nColumn, vector<vector<int>> matrix, vector<vector<int>> &copy) {
//        queue<pair<pair<int, int>, int>> q;
//        q.push({{x, y}, 0});
//        while (!q.empty()) {
//            int x_current = q.front().first.first;
//            int y_current = q.front().first.second;
//            int distance = q.front().second;
//            q.pop();
//            visited[x_current * nColumn + y_current] = true;
//            for (int i = 0; i < 4; i++) {
//                int x_next = x_current + direction[i][0];
//                int y_next = y_current + direction[i][1];
//                if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn &&
//                    !visited[x_next * nColumn + y_next]) {
//                    if (matrix[x_next][y_next] == 0) {
//                        copy[x][y] = distance + 1;
//                        return;
//                    } else {
//                        q.push({{x_next, y_next}, distance + 1});
//                    }
//                }
//            }
//        }
//    }
//};

class Solution {
public:

    bool visited[10000] = {false};
    int direction[4][2] = {{0, 1},
                           {0, -1},
                           {1, 0},
                           {-1, 0}};

    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {

        int nRow = matrix.size();
        int nColumn = matrix[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> copy;
        if (nRow == 0) {
            return copy;
        }
        copy.assign(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            visited[x * nColumn + y] = true;
            for (int i = 0; i < 4; i++) {
                int x_next = x + direction[i][0];
                int y_next = y + direction[i][1];
                if (x_next >= 0 && x_next < nRow && y_next >= 0 && y_next < nColumn &&
                    !visited[x_next * nColumn + y_next] && matrix[x_next][y_next] == 1) {
                    visited[x_next * nColumn + y_next] = true;
                    copy[x_next][y_next] = dis + 1;
                    q.push({{x_next, y_next}, dis + 1});
                }
            }
        }
        return copy;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{0, 1, 0},
                                  {0, 1, 0},
                                  {0, 1, 0},
                                  {0, 1, 0},
                                  {0, 1, 0}};
    solution.updateMatrix(matrix);
}