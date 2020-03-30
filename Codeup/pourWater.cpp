//
// Created by GreenArrow on 2020/2/20.
//
//
#include <queue>
#include <map>
#include <cstdio>

using namespace std;

int m[101][100][99];

typedef struct Contain {
    int a;
    int b;
    int c;

    int step = 0;

    bool operator<(const Contain &o) const {
        return a < o.a || b < o.b || c < o.c;
    }
} Contain;

queue<Contain> Queue;
int a, b, c, k;

int BFS(Contain begin, int k) {

    Queue.push(begin);
    m[begin.a][begin.b][begin.c] = 1;

    while (!Queue.empty()) {

        Contain current = Queue.front();
        //current.print();
        Queue.pop();

        if (current.a == k || current.b == k || current.c == k) {
            printf("yes\n");
            while (!Queue.empty()) Queue.pop();
            return current.step;
        }

        //A->B

        if (current.a > 0 && current.b < b) {
            Contain next;
            int need = b - current.b;
            if (need > current.a) {
                next.b = current.a + current.b;
                next.a = 0;
                next.c = current.c;
            } else {
                next.b = b;
                next.a = current.a - need;
                next.c = current.c;
            }

            if (!m[next.a][next.b][next.c]) {
                m[next.a][next.b][next.c] = 1;
                next.step = current.step + 1;
                Queue.push(next);
            }
        }


        //A->C
        if (current.a > 0 && current.c < c) {
            Contain next;
            int need = c - current.c;
            if (need > current.a) {
                next.c = current.a + current.c;
                next.a = 0;
                next.b = current.b;
            } else {
                next.c = c;
                next.a = current.a - need;
                next.b = current.b;
            }

            if (!m[next.a][next.b][next.c]) {
                m[next.a][next.b][next.c] = 1;
                next.step = current.step + 1;
                Queue.push(next);
            }
        }
        //B->C
        if (current.b > 0 && current.c < c) {
            Contain next;
            int need = c - current.c;
            if (need > current.b) {
                next.c = current.b + current.c;
                next.b = 0;
                next.a = current.a;
            } else {
                next.c = c;
                next.b = current.b - need;
                next.a = current.a;
            }

            if (!m[next.a][next.b][next.c]) {
                m[next.a][next.b][next.c] = 1;
                next.step = current.step + 1;
                Queue.push(next);
            }
        }

        //B->A
        if (current.b > 0 && current.a < a) {
            Contain next;
            int need = a - current.a;
            if (need > current.b) {
                next.a = current.b + current.a;
                next.b = 0;
                next.c = current.c;
            } else {
                next.a = a;
                next.b = current.b - need;
                next.c = current.c;
            }

            if (!m[next.a][next.b][next.c]) {
                m[next.a][next.b][next.c] = 1;
                next.step = current.step + 1;
                Queue.push(next);
            }
        }

        //C->A
        if (current.c > 0 && current.a < a) {
            Contain next;
            int need = a - current.a;
            if (need > current.c) {
                next.a = current.c + current.a;
                next.c = 0;
                next.b = current.b;
            } else {
                next.a = a;
                next.c = current.c - need;
                next.b = current.b;
            }

            if (!m[next.a][next.b][next.c]) {
                m[next.a][next.b][next.c] = 1;
                next.step = current.step + 1;
                Queue.push(next);
            }
        }
        //C->B
        if (current.c > 0 && current.b < b) {
            Contain next;
            int need = b - current.b;
            if (need > current.c) {
                next.b = current.c + current.b;
                next.c = 0;
                next.a = current.a;
            } else {
                next.b = b;
                next.c = current.c - need;
                next.a = current.a;
            }

            if (!m[next.a][next.b][next.c]) {
                m[next.a][next.b][next.c] = 1;
                next.step = current.step + 1;
                Queue.push(next);
            }
        }


    }

    printf("no\n");
    return -1;
}

int main() {
    while (scanf("%d%d%d%d", &a, &b, &c, &k) != EOF) {
        Contain begin;
        if (a == k) {
            printf("yes\n");
            printf("no\n");
            continue;
        }
        begin.a = a;
        begin.b = 0;
        begin.c = 0;
        begin.step = 0;


        memset(m, 0, sizeof(m));


        int c = BFS(begin, k);
        if (c != -1) {
            printf("%d\n", c);
        }
    }
}
