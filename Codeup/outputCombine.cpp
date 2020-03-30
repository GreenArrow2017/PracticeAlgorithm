//
// Created by GreenArrow on 2020/2/18.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int P[10010] = {0};
bool visited[10010] = {false};

void dfs(int index) {

    if (index == m + 1) {
        for (int i = 1; i <= m; ++i) {
            printf("%d ", P[i]);
        }
        printf("\n");
        return;
    }

    for (int j = 1; j <= n; ++j) {


        if (!visited[j]) {
            if (index != 0 && P[index - 1] < j) {
                P[index] = j;
                visited[j] = true;
                dfs(index + 1);
                visited[j] = false;
            }
        }

    }
}

int main() {

    scanf("%d%d", &n, &m);

    dfs(1);


}