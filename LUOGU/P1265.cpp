//
// Created by GreenArrow on 2020/3/7.
//
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cstdio>

#define MAX 5000
using namespace std;

class cordial {
public:
    double x;
    double y;

    cordial(double x, double y) {
        this->x = x;
        this->y = y;
    }

    cordial() {

    }
};
double calculate(cordial a, cordial b);

cordial citys[MAX];
bool visited[MAX] = {false};
double d[MAX];

double prim(int n) {

    double sum = 0;

    fill(d, d + MAX, INT_MAX);
    fill(visited, visited + MAX, false);

    d[0] = 0;

    for (int i = 0; i < n; ++i) {


        int u = -1;
        double MIN = INT_MAX;
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
        sum += d[u];

        for (int k = 0; k < n; ++k) {
            double num = calculate(citys[u], citys[k]);
            if (!visited[k] && d[k] > num) {
                d[k] = num;
            }
        }

    }
    return sum;
}

double calculate(cordial a, cordial b) {
    double xL = a.x - b.x;
    double yL = a.y - b.y;
    return sqrt(xL * xL + yL * yL);
}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        cordial cord(x, y);
        citys[i] = cord;
    }



    printf("%.2lf\n", prim(n));
}
