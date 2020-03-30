//
// Created by GreenArrow on 2020/3/16.
//
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
int chess[202][202];
bool visited[202];


string isMaxClique(int vertex_n, int n, int *array) {


    if(n == 0){
        return "Not a Clique";
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (array[i] != array[j] && chess[array[i]][array[j]] == 0) {
                return "Not a Clique";
            }
        }
    }

    for (int k = 1; k <= vertex_n; ++k) {
        bool flag = true;
        if (!visited[k]) {
            for (int i = 1; i <= vertex_n; ++i) {
                if (i == k) {
                    continue;
                }
                if (!visited[i]) {
                    continue;
                }
                if (chess[k][i] != 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return "Not Maximal";
            }
        }
    }

    return "Yes";

}

int main() {
    int vertex_n, n;
    cin >> vertex_n >> n;

    for (int j = 0; j < 202; ++j) {
        fill(chess[j], chess[j] + 202, 0);
    }

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        chess[a][b] = 1;
        chess[b][a] = 1;
    }

    int k;
    cin >> k;
    int array[k];
    int m;
    for (int i1 = 0; i1 < k; ++i1) {

        cin >> m;
        fill(visited + 1, visited + vertex_n + 1, false);
        for (int l = 0; l < m; ++l) {
            cin >> array[l];
            visited[array[l]] = true;
        }

        cout << isMaxClique(vertex_n, m, array) << endl;

    }
}

//8 10
//5 6

//7 8
//6 4
//3 6
//4 5
//2 3
//8 2
//2 7
//5 3
//3 4
//1
//3 3 2 1