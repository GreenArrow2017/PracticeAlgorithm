//
// Created by GreenArrow on 2020/3/16.
//
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 510
using namespace std;


vector<int> nodes[MAX];
int degree[MAX];

bool visited[MAX];

void BFS(int v) {
    visited[v] = true;
    for (int i = 0; i < nodes[v].size(); ++i) {
        if (!visited[nodes[v][i]]) {
            BFS(nodes[v][i]);
        }
    }
}

int main() {
    int vertex_n, n;
    cin >> vertex_n >> n;

    fill(degree, degree + MAX, 0);
    fill(visited, visited + MAX, false);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    for (int k = 1; k <= vertex_n; ++k) {
        cout << degree[k];
        if (k != vertex_n) {
            cout << " ";
        }
    }

    cout << endl;

    BFS(1);
    int flag_E = true;
    int numberOdd = 0;
    for (int j = 1; j <= vertex_n; ++j) {
        if (!visited[j]) {
            cout << "Non-Eulerian" << endl;
            return 0;
        }

        if (degree[j] % 2 == 1) {
            flag_E = false;
            numberOdd++;
        }
    }

    if (flag_E) {
        cout << "Eulerian" << endl;
        return 0;
    }

    if (numberOdd == 2) {
        cout << "Semi-Eulerian" << endl;
        return 0;
    }

    cout << "Non-Eulerian" << endl;

}

