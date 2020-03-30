//
// Created by GreenArrow on 2020/3/18.
//
#include <iostream>
#include <climits>
#include <vector>

#define MAX 510
using namespace std;

class cost {
public:
    int weight;
    int time;

    cost(int weight, int time) {
        this->weight = weight;
        this->time = time;
    }

    cost() {}
};

cost chess[MAX][MAX];
int d[MAX];
int t[MAX];
int path_d[MAX];
int path_t[MAX];
int visited_d[MAX];
int visited_t[MAX];
int times[MAX];
int size_time[MAX];

vector<int> distances;
vector<int> take_time;

bool equal(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void print_path_d(int start, int end) {
    if (start != end) {
        print_path_d(start, path_d[end]);
        distances.push_back(end);
    } else {
        distances.push_back(start);
    }
}

void print_path_t(int start, int end) {
    if (start != end) {
        print_path_t(start, path_t[end]);
        take_time.push_back(end);
    } else {
        take_time.push_back(start);
    }
}

void Dijiskra_d(int s, int n) {
    fill(d, d + MAX, INT_MAX);
    fill(visited_d, visited_d + MAX, false);
    fill(times, times + MAX, 0);
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        int min = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited_d[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        visited_d[u] = true;
        for (int k = 0; k < n; ++k) {
            if (!visited_d[k] && chess[u][k].weight != INT_MAX) {
                if (d[k] > d[u] + chess[u][k].weight) {
                    d[k] = d[u] + chess[u][k].weight;
                    times[k] = times[u] + chess[u][k].time;
                    path_d[k] = u;
                } else if (d[k] == d[u] + chess[u][k].weight) {
                    if (times[k] > times[u] + chess[u][k].time) {
                        times[k] = times[u] + chess[u][k].time;
                        path_d[k] = u;
                    }
                }
            }
        }
    }
}

void Dijiskra_t(int s, int n) {
    fill(t, t + MAX, INT_MAX);
    fill(visited_t, visited_t + MAX, false);
    fill(size_time, size_time + MAX, 0);
    size_time[s] = 1;
    t[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        int min = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (!visited_t[j] && t[j] < min) {
                u = j;
                min = t[j];
            }
        }

        visited_t[u] = true;

        for (int k = 0; k < n; ++k) {
            if (!visited_t[k] && chess[u][k].time != INT_MAX) {
                if (t[k] > t[u] + chess[u][k].time) {
                    t[k] = t[u] + chess[u][k].time;
                    size_time[k] = size_time[u] + 1;
                    path_t[k] = u;
                } else if (t[k] == t[u] + chess[u][k].time) {
                    if (size_time[k] > size_time[u] + 1) {
                        size_time[k] = size_time[u] + 1;
                        path_t[k] = u;
                    }
                }
            }
        }
    }
}

int main() {
    fill(chess[0], chess[0] + MAX * MAX, cost(INT_MAX, INT_MAX));


    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, one_way, length, time;
        cin >> a >> b >> one_way >> length >> time;
        chess[a][b] = cost(length, time);
        if (!one_way) {
            chess[b][a] = cost(length, time);
        }
    }

    int start, stop;
    cin >> start >> stop;

    Dijiskra_d(start, n);

    Dijiskra_t(start, n);

    print_path_d(start, stop);

    print_path_t(start, stop);

    if (equal(distances, take_time)) {
        cout << "Distance = " << d[stop] << "; Time = " << t[stop] << ": ";
        for (int i = 0; i < take_time.size(); ++i) {
            cout << take_time[i];
            if (take_time.size() - 1 != i) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "Distance = " << d[stop] << ": ";
        for (int i = 0; i < distances.size(); ++i) {
            cout << distances[i];
            if (distances.size() - 1 != i) {
                cout << " -> ";
            }
        }
        cout << endl;

        cout << "Time = " << t[stop] << ": ";
        for (int i = 0; i < take_time.size(); ++i) {
            cout << take_time[i];
            if (take_time.size() - 1 != i) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

}
