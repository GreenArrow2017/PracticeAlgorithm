//
// Created by GreenArrow on 2020/3/5.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cstdio>

#define MAX 410
using namespace std;

class hourse {
public:
    int x, y;

    hourse(int x, int y) {
        this->x = x;
        this->y = y;
    }

    hourse() {

    }
};

int chess[MAX][MAX] = {-1};
bool visited[MAX][MAX] = {false};
int moveOn[8][2] = {{-2, 1},
                    {-1, 2},
                    {1,  2},
                    {2,  1},
                    {2,  -1},
                    {1,  -2},
                    {-1, -2},
                    {-2, -1}};

void BFS(int N, int M, hourse begin) {

    queue<hourse> Queue;
    Queue.push(begin);
    chess[begin.x][begin.y] = 0;
    visited[begin.x][begin.y] = true;
    while (!Queue.empty()) {
        hourse cur = Queue.front();
        Queue.pop();
        for (int i = 0; i < 8; ++i) {
            hourse next(cur.x + moveOn[i][0], cur.y + moveOn[i][1]);
            if (next.x >= 0 && next.x < N && next.y >= 0 && next.y < M && !visited[next.x][next.y]) {
                visited[next.x][next.y] = true;
                chess[next.x][next.y] = chess[cur.x][cur.y] + 1;
                Queue.push(next);
            }
        }
    }
}

int main() {

    for (int k = 0; k < MAX; ++k) {
        fill(chess[k], chess[k] + MAX, -1);
        fill(visited[k], visited[k] + MAX, false);
    }

    int N, M;
    int x, y;
    cin >> N >> M >> x >> y;
    x--;
    y--;
    hourse begin(x, y);
    BFS(N, M, begin);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%-5d", chess[i][j]);
        }
        cout << endl;
    }
}