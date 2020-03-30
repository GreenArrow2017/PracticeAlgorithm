//
// Created by GreenArrow on 2020/2/24.
//

#include <iostream>
#include <vector>

#define max 10010

using namespace std;
bool visited[max] = {true};
vector<int> adj[max];
int number = 0;

void DFS(int v) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); ++i) {
        int u = adj[v][i];
        if (!visited[u]) {
            DFS(u);
        }
    }
}

void DFSTrave(int n) {
    for (int i = 0; i <= n; ++i) {
        if (!visited[i]) {
            number++;
            DFS(i);
        }
    }
}



int main() {
    int n, m;
    int sum = 0;

    for (int j = 0; j < max; ++j) {
        visited[j] = true;
    }

//    for (int i = 0; i < 10; ++i) {
//        if(!visited[i]){
//            cout << i << endl;
//        }
//    }

    while (cin >> n >> m) {
        cin.ignore();
        adj[n].push_back(m);
        adj[m].push_back(n);
        visited[n] = false;
        visited[m] = false;
        int pre = (n > m) ? n : m;
        sum = (sum > pre) ? sum : pre;
    }


    //cout << sum << endl;

    DFSTrave(sum);

    cout << number << endl;

}