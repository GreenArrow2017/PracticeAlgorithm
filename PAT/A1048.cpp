//
// Created by GreenArrow on 2020/4/1.
//
#include <algorithm>
#include <iostream>

#define MAX 1001
#define max 10020
using namespace std;


int main() {
    int visited[MAX];
    fill(visited, visited + MAX, 0);
    int n, total;
    cin >> n >> total;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        visited[num]++;
    }

    int v1 = -1, v2 = -1;

    for (int j = 0; j < MAX; ++j) {
        if (visited[j]) {
            visited[j]--;
            if (total > j && visited[total - j]) {
                cout << j << " " << total - j;
                return 0;
            }
        }
    }

    cout << "No Solution";

}