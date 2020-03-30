//
// Created by GreenArrow on 2020/2/18.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef struct LNode {
    char data;
    int next;
    bool flag = false;
} Node, *linklist;

int main() {
    Node node[100010];

    int s1, s2, n;
    cin >> s1 >> s2 >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        int address, next;
        char data;
        cin >> address >> data >> next;
        node[address].data = data;
        node[address].next = next;
    }

    for (int i = s1; i != -1; i = node[i].next) {
        node[i].flag = true;
    }

    int j = 0;
    for (j = s2; j != -1; j = node[j].next) {
        if (node[j].flag) {
            break;
        }
    }

    if (j != -1) {
        printf("%05d\n", j);
    } else
        printf("-1\n");

}
