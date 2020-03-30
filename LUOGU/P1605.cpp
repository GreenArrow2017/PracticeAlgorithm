//
// Created by GreenArrow on 2020/3/2.
//
#include <iostream>

#define MAX 10
using namespace std;
int chess[MAX][MAX] = {0};
int count_number = 0;
typedef struct node {
    int x;
    int y;
} *Node, node;

bool move(int direction, Node begin, int N, int M, Node &moveOn) {
    //往上走
    if (direction == 0) {
        if (begin->x <= 1 || (chess[begin->x - 1][begin->y])) {
            return false;
        }
        moveOn->x = begin->x - 1;
        moveOn->y = begin->y;
        //往下走
    } else if (direction == 1) {
        if (begin->x >= N || (chess[begin->x + 1][begin->y])) {
            return false;
        }
        moveOn->x = begin->x + 1;
        moveOn->y = begin->y;
        //往左走
    } else if (direction == 2) {
        if (begin->y <= 1 || (chess[begin->x][begin->y - 1])) {
            return false;
        }
        moveOn->x = begin->x;
        moveOn->y = begin->y - 1;
        //往右走
    } else if (direction == 3) {
        if (begin->y >= M || (chess[begin->x][begin->y + 1])) {
            return false;
        }
        moveOn->x = begin->x;
        moveOn->y = begin->y + 1;
    }
    return true;
}

void findWay(Node begin, Node end, int N, int M) {
    if (begin->x == end->x && begin->y == end->y) {
        count_number++;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        Node moveOn = new node;
        bool flag = move(i, begin, N, M, moveOn);
        if (flag) {
            chess[moveOn->x][moveOn->y] = 1;
            findWay(moveOn, end, N, M);
            chess[moveOn->x][moveOn->y] = 0;
        }
    }
}


int main() {
    int N, M;
    int n;
    cin >> N >> M >> n;
    Node begin = new node;
    Node end = new node;

    cin >> begin->x;
    cin >> begin->y;
    cin >> end->x;
    cin >> end->y;

    chess[begin->x][begin->y] = 1;

    for (int i = 0; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        chess[x][y] = 1;
    }

    findWay(begin, end, N, M);
    cout << count_number << endl;

}
