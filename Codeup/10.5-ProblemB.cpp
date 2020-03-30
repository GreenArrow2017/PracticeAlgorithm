//
// Created by GreenArrow on 2020/2/29.
//
#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define MAX 110
using namespace std;

typedef struct point {
    double x;
    double y;
} *Point, point;

double calculateDistance(Point a, Point b) {
    double minusX = a->x - b->x;
    double minusY = a->y - b->y;
    double sum = minusX * minusX + minusY * minusY;
    return sqrt(sum);
}

double Graph[MAX][MAX];
bool visited[MAX] = {false};
double d[MAX] = {INT_MAX};

void print_test(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}

double prim(int n, int s) {
    fill(visited, visited + MAX, false);
    fill(d, d + MAX, INT_MAX);
    double ans = 0;
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        double MIN = INT_MAX;
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && MIN > d[j]) {
                MIN = d[j];
                u = j;
            }
        }

        if (u == -1) {
            return -1;
        }
        visited[u] = true;
        ans += d[u];

        for (int k = 0; k < n; ++k) {
            if (!visited[k] && Graph[u][k] != INT_MAX && d[k] > Graph[u][k]) {
                d[k] = Graph[u][k];
            }
        }
    }

    return ans;
}

int main() {
    int N;
    while (cin >> N) {
        if(N == 0){
            return 0;
        }
        Point nodes[N];
        for (int i = 0; i < N; ++i) {
            double x, y;
            cin >> x >> y;
            Point a = new point;
            a->x = x;
            a->y = y;
            nodes[i] = a;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    Graph[i][j] = 0;
                } else if (i < j) {
                    Graph[i][j] = calculateDistance(nodes[i], nodes[j]);
                } else if (i > j) {
                    Graph[i][j] = Graph[j][i];
                }
            }
        }


        //print_test(N);
        double result = prim(N, 0);
        printf("%.2lf\n", result);

    }
}
