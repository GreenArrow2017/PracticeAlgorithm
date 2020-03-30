//
// Created by GreenArrow on 2020/2/19.
//
#include <cstdio>

int count_stack = 0;

void dfs(int sum, int in, int out, int n) {
    if (in < n) {
        dfs(sum + 1, in + 1, out, n);
    }
    if (out < n && sum > 0) {
        dfs(sum - 1, in, out + 1, n);
    }

    if (out == n) {
        count_stack++;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {

        count_stack = 0;
        dfs(0, 0, 0, n);
        printf("%d\n", count_stack);
    }
}
