//
// Created by GreenArrow on 2020/3/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 120
using namespace std;

int main() {
    int n;
    int visited[MAX];
    int a[MAX];
    vector<int> lieis;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> visited[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            //i, j is lier
            lieis.clear();
            fill(a, a + MAX, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; ++k) {
                if (visited[k] * a[abs(visited[k])] < 0)
                    lieis.push_back(k);
            }
            if (lieis.size() == 2 && a[lieis[0]] + a[lieis[1]] == 0) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
}