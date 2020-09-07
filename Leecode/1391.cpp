//
// Created by GreenArrow on 2020/7/26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[302][302] = {false};

class Solution {
public:

    int x_end;
    int y_end;

    //上  下  左  右
    int maps[7][4] = {
            {0,  0,  0,  0},
            {-1, -1, 1,  1},
            {1,  1,  -1, -1},
            {-1, 1,  1,  -1},
            {-1, 1,  -1, 1},
            {1,  -1, 1,  -1},
            {1,  -1, -1, 1}
    };

    int director[4][2] = {
            {-1, 0},//upward
            {1,  0},//downward
            {0,  -1},//left
            {0,  1}//right
    };


    bool hasValidPath(vector<vector<int>> &grid) {

        for (int i = 0; i < 302; i++) {
            fill(visited[i], visited[i] + 302, false);
        }

        int nRow = grid.size();
        int nColumn = grid[0].size();

        x_end = nRow - 1;
        y_end = nColumn - 1;

        return dfs(0, 0, nRow, nColumn, grid);
    }


    bool dfs(int x, int y, int nRow, int nColumn, vector<vector<int>> grid) {
        visited[x][y] = true;
        if (x == x_end && y == y_end) {
            return true;
        }
        int indexOfGrid = grid[x][y];
        for (int i = 0; i < 4; i++) {
            if (maps[indexOfGrid][i] != -1) {
                int next_x = x + director[i][0], next_y = y + director[i][1];
                if (next_x >= 0 && next_x < nRow && next_y >= 0 && next_y < nColumn &&
                    !visited[next_x][next_y]) {
                    //从上面进入，下一块有没有下面的通道
                    if (i == 0 && maps[grid[next_x][next_y]][1] == 1) {
                        if (dfs(next_x, next_y, nRow, nColumn, grid)) {
                            return true;
                        }
                    } else if (i == 1 && maps[grid[next_x][next_y]][0] == 1) {
                        if (dfs(next_x, next_y, nRow, nColumn, grid)) {
                            return true;
                        }
                    } else if (i == 2 && maps[grid[next_x][next_y]][3] == 1) {
                        if (dfs(next_x, next_y, nRow, nColumn, grid)) {
                            return true;
                        }
                    } else if (i == 3 && maps[grid[next_x][next_y]][2] == 1) {
                        if (dfs(next_x, next_y, nRow, nColumn, grid)) {
                            return true;
                        }
                    }

                }
            }
        }
        return false;
    }
};


//class Solution {
//public:
//
//    bool visited[1000][1000] = {false};
//
//    class cordinate {
//    public:
//        int x;
//        int y;
//
//        cordinate(int x, int y) {
//            this->x = x;
//            this->y = y;
//        }
//    };
//
//    int director[4][2] = {
//            {0,  1},
//            {0,  -1},
//            {1,  0},
//            {-1, 0}
//    };
//
//    int picture_mapper[7][2] = {
//            {0, 0},
//            {0, 1},
//            {2, 3},
//            {1, 2},
//            {2, 0},
//            {1, 3},
//            {3, 0}
//    };
//
//    bool hasValidPath(vector<vector<int>> &grid) {
//
//        for (int i = 0; i < 1000; i++)
//            fill(visited[i], visited[i] + 1000, false);
//        int nRow = grid.size();
//        int nColumn = grid[0].size();
//        cordinate beginning(0, 0);
//        cordinate ending(nRow - 1, nColumn - 1);
//
//        return dfs(beginning, ending, nRow, nColumn, grid);
//
//    }
//
//    bool dfs(cordinate beginning, cordinate ending, int nRow, int nColumn, vector<vector<int>> grid) {
//
//        visited[beginning.x][beginning.y] = true;
//        if (beginning.x == ending.x && beginning.y == ending.y) {
//            return true;
//        }
//
//        int indexOfGrid = grid[beginning.x][beginning.y];
//        for (int i = 0; i < 2; i++) {
//            int x_step = director[picture_mapper[indexOfGrid][i]][0];
//            int y_step = director[picture_mapper[indexOfGrid][i]][1];
//            cordinate next(beginning.x + x_step, beginning.y + y_step);
//            if (next.x >= 0 && next.x < nRow && next.y >= 0 && next.y < nColumn &&
//                !visited[next.x][next.y] &&
//                match(x_step, y_step, next, grid)) {
//                if (dfs(next, ending, nRow, nColumn, grid)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//
//    }
//
//    bool match(int x_direction, int y_direction, cordinate next, vector<vector<int>> grid) {
//        int indexOfGrid = grid[next.x][next.y];
//        for (int i = 0; i < 2; i++) {
//            if (x_direction == 0 &&
//                y_direction == 1 &&
//                director[picture_mapper[indexOfGrid][i]][0] == 0 &&
//                director[picture_mapper[indexOfGrid][i]][1] == -1) {
//                return true;
//            } else if (x_direction == 0 &&
//                       y_direction == -1 &&
//                       director[picture_mapper[indexOfGrid][i]][0] == 0 &&
//                       director[picture_mapper[indexOfGrid][i]][1] == 1) {
//                return true;
//            } else if (x_direction == 1 &&
//                       y_direction == 0 &&
//                       director[picture_mapper[indexOfGrid][i]][0] == -1 &&
//                       director[picture_mapper[indexOfGrid][i]][1] == 0) {
//                return true;
//            } else if (x_direction == -1 &&
//                       y_direction == 0 &&
//                       director[picture_mapper[indexOfGrid][i]][0] == 1 &&
//                       director[picture_mapper[indexOfGrid][i]][1] == 0) {
//                return true;
//            }
//        }
//        return false;
//    }
//};

int main() {
    vector<vector<int>> test = {{4, 1, 3},
                                {6, 1, 2}};
    Solution solution;
    cout << solution.hasValidPath(test);
}
