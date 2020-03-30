#include<cstdio>

using namespace std;

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n), m != 0 || n != 0) {
        int left, right, cnt = 0;
        left = right = m;
        while (left <= n) {
            cnt += right - left + 1;
            left = left * 2;
            right = right * 2 + 1;
            if (right > n) right = n;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
