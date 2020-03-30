//
// Created by GreenArrow on 2020/2/19.
//
#include <iostream>
#include <cstdio>

#define max 100
using namespace std;

int count_ = 0;

typedef struct point {
    int x;
    int y;
} *Point, point;

bool check(int maze[][max], Point nowCorr, int n, int m);

void print(Point *result, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "(" << result[i]->x + 1 << "," << result[i]->y + 1 << ")";
        if (i != n - 1) {
            printf("->");
        }
    }
    printf("\n");
}

void dfs(bool (&visited)[max][max], int maze[][max], Point begin, Point end, int index, Point *result, int n, int m) {


    if (begin->x == end->x && begin->y == end->y) {
        print(result, index);
        count_++;
        return;
    }

    Point next = new point;


    next->x = begin->x;
    next->y = begin->y - 1;
    if (check(maze, next, n, m) && (!visited[next->x][next->y])) {
        visited[next->x][next->y] = true;
        result[index] = next;
        dfs(visited, maze, next, end, index + 1, result, n, m);
        visited[next->x][next->y] = false;
    }

    next->x = begin->x - 1;
    next->y = begin->y;
    if (check(maze, next, n, m) && (!visited[next->x][next->y])) {
        visited[next->x][next->y] = true;
        result[index] = next;
        dfs(visited, maze, next, end, index + 1, result, n, m);
        visited[next->x][next->y] = false;
    }

    next->x = begin->x;
    next->y = begin->y + 1;
    if (check(maze, next, n, m) && (!visited[next->x][next->y])) {
        visited[next->x][next->y] = true;
        result[index] = next;
        dfs(visited, maze, next, end, index + 1, result, n, m);
        visited[next->x][next->y] = false;
    }


    next->x = begin->x + 1;
    next->y = begin->y;
    if (check(maze, next, n, m) && (!visited[next->x][next->y])) {
        visited[next->x][next->y] = true;
        result[index] = next;
        dfs(visited, maze, next, end, index + 1, result, n, m);
        visited[next->x][next->y] = false;
    }


}

bool check(int maze[][max], Point nowCorr, int n, int m) {

    if ((nowCorr->x < n) && (nowCorr->x >= 0) && (nowCorr->y < m) && (nowCorr->y >= 0)) {
        if (maze[nowCorr->x][nowCorr->y] == 1) {
            return true;
        }
    }
    return false;

}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int maze[max][max];
    bool visited[max][max] = {false};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &maze[i][j]);
        }
    }

    Point begin = new point;
    Point end = new point;

    scanf("%d %d", &begin->x, &begin->y);
    scanf("%d %d", &end->x, &end->y);

    begin->x--;
    begin->y--;
    end->x--;
    end->y--;

    Point result[max];

    for (int k = 0; k < max; ++k) {
        result[k] = new point;
    }

    result[0] = begin;
    visited[begin->x][begin->y] = true;

    dfs(visited, maze, begin, end, 1, result, n, m);


    if (count_ == 0) {
        cout << "-1" << endl;
    }


    return 0;
}