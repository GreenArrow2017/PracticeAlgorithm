#include<iostream>
#include<vector>
#include <climits>
#include <vector>

#define MAX 510
using namespace std;

int bikes[MAX];
int chess[MAX][MAX];
int minSend = INT_MAX, minBack = INT_MAX, minDis = INT_MAX;
bool visited[MAX];
vector<int> path, tempPath;
int capacity, n, ed, m;

void DFS(int s, int end, int tempSend, int tempBack, int tempDis) {
    visited[s] = true;
    tempPath.push_back(s);

    if (s == end) {
        if (minDis > tempDis) {
            path = tempPath;
            minDis = tempDis;
            minSend = tempSend;
            minBack = tempBack;
        } else if (minDis == tempDis) {
            if (minSend > tempSend) {
                path = tempPath;
                minSend = tempSend;
                minBack = tempBack;
            } else if (minSend == tempSend) {
                if (minBack > tempBack) {
                    path = tempPath;
                    minSend = tempSend;
                    minBack = tempBack;
                }
            }
        }
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && chess[s][i] != INT_MAX) {

            int temp = bikes[i] - capacity / 2;
            int tempB = tempBack;
            int tempS = tempSend;
            if (temp >= 0) {
                tempB += temp;
            } else {
                if (temp + tempB < 0) {
                    tempS -= (temp + tempB);
                    tempB = 0;
                } else {
                    tempB = (temp + tempB);
                }
            }
            DFS(i, end, tempS, tempB, tempDis + chess[s][i]);
            tempPath.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    fill(chess[0], chess[0] + MAX * MAX, INT_MAX);
    cin >> capacity >> n >> ed >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> bikes[i];
    }
    n++;
    for (int j = 0; j < m; ++j) {
        int a, b, weight;
        cin >> a >> b >> weight;
        chess[a][b] = weight;
        chess[b][a] = weight;
    }

    fill(visited, visited + MAX, false);

    DFS(0, ed, 0, 0, 0);

    cout << minSend << " ";

    for (int k = 0; k < path.size(); ++k) {
        cout << path[k];
        if (k != path.size() - 1) {
            cout << "->";
        }
    }
    cout << " ";
    cout << minBack;
}