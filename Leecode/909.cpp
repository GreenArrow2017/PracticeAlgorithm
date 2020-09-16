//
// Created by GreenArrow on 2020/9/11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    map<int, pair<int, int>> map_vector;
    map<pair<int, int>, int> vector_map;

    int snakesAndLadders(vector<vector<int>> &board) {
        int nRow = board.size();
        int nColumn = board[0].size();
        int end = fillMap(board, nRow, nColumn);

        visited.resize(end + 1);

        return bfs(board, nRow, nColumn, 1, end);

    }

    int bfs(vector<vector<int>> &board, int nRow, int nColumn, int start, int end) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            int current = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (current == end) {
                return depth;
            }
            for (int i = 1; i <= 6; i++) {
                int next = current + i;
                int next_x = map_vector[next].first;
                int next_y = map_vector[next].second;
                if (board[next_x][next_y] != -1) {
                    next = board[next_x][next_y];
                }
                if(visited[next]){
                    continue;
                }
                visited[next] = true;
                q.push({next, depth + 1});
            }
        }
        return -1;
    }

    int fillMap(vector<vector<int>> &board, int nRow, int nColumn) {

        int index = 0;
        bool flag = true;
        for (int i = nRow - 1; i >= 0; i--) {
            if (flag) {
                for (int j = 0; j < nColumn; j++) {
                    index++;
                    map_vector[index] = {i, j};
                    vector_map[{i, j}] = index;
                }
                flag = false;
            } else {
                for (int j = nColumn - 1; j >= 0; j--) {
                    index++;
                    map_vector[index] = {i, j};
                    vector_map[{i, j}] = index;
                }
                flag = true;
            }
        }
        return index;

    }
};

//[[1,1,-1],
// [1,1,1],
// [-1,1,1]]