#include <cstdio>

int n, k, p[22];
int count;

bool isprime(int c) {
    if (c < 2)
        return false;
    for (int i = 2; i * i <= c; ++i) {
        if (c % i == 0)
            return false;
    }
    return true;
}

void Dfs(int index, int nowk, int sum) {
    if (nowk == k) {
        if (isprime(sum))
            count++;
        return;
    }
    if (index == n || nowk > k)
        return;
    Dfs(index + 1, nowk + 1, sum + p[index]);
    Dfs(index + 1, nowk, sum);
}

int main() {
    count = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    Dfs(0, 0, 0);
    printf("%d\n", count);
    return 0;
}