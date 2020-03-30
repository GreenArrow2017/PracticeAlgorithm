//
// Created by GreenArrow on 2020/3/18.
//
#include <iostream>
#include <map>
#include <climits>
#include <vector>

#define MAX 210
using namespace std;


map<string, int> exits;

class city {
public:
    string name;
    int happy;

    city() {}

    city(string name, int happy) {
        this->name = name;
        this->happy = happy;
    }
};

city name[MAX];
int chess[MAX][MAX];
bool visited[MAX];
int d[MAX];
int happy_total[MAX];
int num[MAX];
int path[MAX];
vector<int> paths;

void print_path(int start, int end) {
    if (start != end) {
        print_path(start, path[end]);
        paths.push_back(end);
    } else {
        paths.push_back(start);
    }
}


void Dijiskra(int s, int n) {
    fill(visited, visited + MAX, false);
    fill(d, d + MAX, INT_MAX);
    fill(happy_total, happy_total + MAX, 0);
    fill(num, num + MAX, 0);
    num[s] = 1;
    d[s] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        int min = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        visited[u] = true;
        if (u == -1)
            return;

        for (int k = 0; k < n; ++k) {
            if (!visited[k] && chess[u][k] != INT_MAX) {
                if (d[k] > d[u] + chess[u][k]) {
                    d[k] = d[u] + chess[u][k];
                    happy_total[k] = happy_total[u] + name[k].happy;
                    num[k] = num[u];
                    path[k] = u;
                } else if (d[k] == d[u] + chess[u][k]) {
                    num[k] += num[u];
                    if (happy_total[k] < happy_total[u] + name[k].happy) {
                        happy_total[k] = happy_total[u] + name[k].happy;
                        path[k] = u;
                    }
                }
            }
        }
    }
}

int main() {
    fill(chess[0], chess[0] + MAX * MAX, INT_MAX);
    int n, m;
    string s;
    cin >> n >> m >> s;
    name[0] = city(s, 0);
    exits[s] = 0;

    int start = 0;
    int stop = 0;

    for (int i = 1; i < n; ++i) {
        string c;
        int happy;
        cin >> c >> happy;
        if (c == "ROM") {
            stop = i;
        }
        name[i] = city(c, happy);
        exits[c] = i;
    }

    for (int j = 0; j < m; ++j) {
        string a, b;
        int weight;
        cin >> a >> b >> weight;
        int A = exits[a];
        int B = exits[b];
        chess[A][B] = weight;
        chess[B][A] = weight;
    }

    Dijiskra(start, n);

    print_path(start, stop);

    cout << num[stop] << " " << d[stop] << " " << happy_total[stop] << " " << happy_total[stop] / (paths.size() - 1)
         << endl;
    for (int k = 0; k < paths.size(); ++k) {
        cout << name[paths[k]].name;
        if (k != paths.size() - 1) {
            cout << "->";
        }
    }

}
