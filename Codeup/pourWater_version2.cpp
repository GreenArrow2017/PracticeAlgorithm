#include<stdio.h>
#include<map>
#include<queue>
#include<string.h>

using namespace std;
int ans;
struct Node {
    int a[3];//此时容器有的油量
    int step;

} s;
int num[3];
int m[101][101][101];

int bfs() {
    queue<Node> q;
    s.step = 0;
    q.push(s);
    m[s.a[0]][s.a[1]][s.a[2]] = 1;
    int flag = 0;
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        if (top.a[0] == ans || top.a[1] == ans || top.a[2] == ans) {
            printf("yes\n");
            printf("%d\n", top.step);
            return 1;
        }
        Node t;
        for (int i = 0; i <= 2; i++) {

            for (int j = 0; j <= 2; j++) {
                int rest = num[j] - top.a[j];
                if (i != j && rest != 0) {
                    t = top;
                    if (top.a[i] > rest)//j倒满
                    {
                        t.a[i] = top.a[i] - rest;
                        t.a[j] = num[j];
                        t.step = top.step + 1;
                    } else {
                        t.a[i] = 0;
                        t.a[j] = top.a[i] + top.a[j];
                        t.step = top.step + 1;
                    }
                    if (m[t.a[0]][t.a[1]][t.a[2]] == 0) {
                        q.push(t);
                        m[t.a[0]][t.a[1]][t.a[2]] = 1;
                    }
                }
            }

        }
    }
    return 0;
}

int main() {
    while (scanf("%d %d %d %d", &num[0], &num[1], &num[2], &ans) != EOF) {
        memset(m, 0, sizeof(m));
        s.a[0] = num[0];
        s.a[1] = 0;
        s.a[2] = 0;
        int flag = bfs();
        if (flag == 0) {
            printf("no\n");
        }
    }
    return 0;
}

