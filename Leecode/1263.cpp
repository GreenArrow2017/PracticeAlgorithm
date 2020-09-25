struct Dwell {
    int box_x, box_y;
    int man_x, man_y;
    Dwell(int _bx, int _by, int _mx, int _my): box_x(_bx), box_y(_by), man_x(_mx), man_y(_my) {}
};

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dist[m][n][m][n];
        memset(dist, -1, sizeof(dist));

        int box_x, box_y;
        int start_x, start_y;
        int end_x, end_y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'B') {
                    box_x = i;
                    box_y = j;
                    grid[i][j] = '.';
                }
                else if (grid[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                    grid[i][j] = '.';
                }
                else if (grid[i][j] == 'T') {
                    end_x = i;
                    end_y = j;
                    grid[i][j] = '.';
                }
            }
        }

        queue<Dwell> q;
        q.emplace(box_x, box_y, start_x, start_y);
        dist[box_x][box_y][start_x][start_y] = 0;

        while (!q.empty()) {
            queue<Dwell> nq;
            while (!q.empty()) {
                Dwell cur = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int nxt_x = cur.man_x + dirs[i][0];
                    int nxt_y = cur.man_y + dirs[i][1];
                    if (nxt_x >= 0 && nxt_x < m && nxt_y >= 0 && nxt_y < n) {
                        if (cur.box_x == nxt_x && cur.box_y == nxt_y) {
                            int nxt_box_x = cur.box_x + dirs[i][0];
                            int nxt_box_y = cur.box_y + dirs[i][1];
                            if (nxt_box_x >= 0 && nxt_box_x < m && nxt_box_y >= 0 && nxt_box_y < n) {
                                if (grid[nxt_box_x][nxt_box_y] == '.' && dist[nxt_box_x][nxt_box_y][nxt_x][nxt_y] == -1) {
                                    nq.emplace(nxt_box_x, nxt_box_y, nxt_x, nxt_y);
                                    dist[nxt_box_x][nxt_box_y][nxt_x][nxt_y] = dist[cur.box_x][cur.box_y][cur.man_x][cur.man_y] + 1;
                                    if (nxt_box_x == end_x && nxt_box_y == end_y) {
                                        return dist[nxt_box_x][nxt_box_y][nxt_x][nxt_y];
                                    }
                                }
                            }
                        }
                        else {
                            if (grid[nxt_x][nxt_y] == '.' && dist[cur.box_x][cur.box_y][nxt_x][nxt_y] == -1) {
                                q.emplace(cur.box_x, cur.box_y, nxt_x, nxt_y);
                                dist[cur.box_x][cur.box_y][nxt_x][nxt_y] = dist[cur.box_x][cur.box_y][cur.man_x][cur.man_y];
                            }
                        }
                    }
                }
            }
            q = nq;
        }


        return -1;
    }
};
