//
// Created by GreenArrow on 2020/2/25.
//

#include <iostream>
#include <vector>

#define max 1010
using namespace std;

bool visited[max] = {false};
int n, m;
vector<int> Adj[max];

void DFS(int v, int number) {
    visited[v] = true;
    for (int i = 0; i < Adj[v].size(); ++i) {
        int c = Adj[v][i];
        if (!visited[c]) {
            DFS(c, number);
        }
    }
}

void DFStraval(int number) {
    int ans = 0;
    for (int i = 1; i <= number; ++i) {

        if (!visited[i]) {
            ans++;
            DFS(i, number);
        }

        if (ans > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    if (ans == 1 || (ans == 0 && number == 1)) {
        cout << "YES" << endl;
    }
    return;
}

int main() {
    while (cin >> n >> m) {
        cin.ignore();
        if (n == 0) {
            return 0;
        }

        for (int i = 0; i < max; ++i) {
            visited[i] = false;
        }

        for (int k = 0; k < max; ++k) {
            Adj[k].clear();
        }

        for (int j = 0; j < m; ++j) {
            int a, b;
            cin >> a >> b;
            cin.ignore();
            Adj[a].push_back(b);
            Adj[b].push_back(a);
        }

//        for (int l = 0; l <= maxNode; ++l) {
//            cout << visited[l] << " ";
//        }
//        cout << endl;


        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }
        DFStraval(n);

    }
}