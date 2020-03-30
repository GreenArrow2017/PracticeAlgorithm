//
// Created by GreenArrow on 2020/3/3.
//
#include <iostream>
#include <vector>
#include <queue>

#define MAX 40
using namespace std;
int chess[MAX][MAX];
int n;

class node {
public:
    int x;
    int y;

    node(int x, int y) {
        this->x = x;
        this->y = y;
    }

    node() {

    }
};

void print_test() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isMove(node current, int direction) {
    //向上走
    if (direction == 0) {
        if (current.x <= 0 || chess[current.x - 1][current.y]) {
            return false;
        }
        //向下走
    } else if (direction == 1) {
        if (current.x >= n || chess[current.x + 1][current.y]) {
            return false;
        }
        //向左走
    } else if (direction == 2) {
        if (current.y <= 0 || chess[current.x][current.y - 1]) {
            return false;
        }
        //向右走
    } else if (direction == 3) {
        if (current.y >= n || chess[current.x][current.y + 1]) {
            return false;
        }
    }
    return true;
}

void BFS() {
    vector<node> point_margin;
    for (int i = 0; i < n; ++i) {
        if (chess[0][i] == 0) {
            point_margin.push_back(node(0, i));
        }
        if (chess[i][0] == 0) {
            point_margin.push_back(node(i, 0));
        }
        if (chess[n - 1][i] == 0) {
            point_margin.push_back(node(n - 1, i));
        }
        if (chess[i][n - 1] == 0) {
            point_margin.push_back(node(i, n - 1));
        }
    }


    queue<node> Queue;
    for (int j = 0; j < point_margin.size(); ++j) {
        node start = point_margin[j];
        Queue.push(start);
        while (!Queue.empty()) {
            node judge = Queue.front();
            chess[judge.x][judge.y] = 3;
            Queue.pop();
            for (int i = 0; i < 4; ++i) {
                if (isMove(judge, i)) {
                    node next;
                    if (i == 0) {
                        next.x = judge.x - 1;
                        next.y = judge.y;
                    } else if (i == 1) {
                        next.x = judge.x + 1;
                        next.y = judge.y;
                    } else if (i == 2) {
                        next.x = judge.x;
                        next.y = judge.y - 1;
                    } else if (i == 3) {
                        next.x = judge.x;
                        next.y = judge.y + 1;
                    }

                    Queue.push(next);
                }
            }
        }
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> chess[i][j];
        }
    }

    BFS();


    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (chess[k][i] == 3) {
                cout << "0 ";
            } else if(chess[k][i] == 1){
                cout << "1 ";
            } else if(chess[k][i] == 0){
                cout << "2 ";
            }
        }
        cout << endl;
    }
}
